/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:41:44 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/03 16:23:16 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("pipex: input");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	if (dup2(fd[1], 1) == -1)
	{
		perror("pipex: dup2");
		exit(1);
	}
	if (dup2(infile, 0) == -1)
	{
		perror("pipex: dup2");
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute_cmd(argv[2], envp);
	exit(127);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("pipex: output");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	if (dup2(fd[0], 0) == -1)
	{
		perror("pipex: dup2");
		exit(1);
	}
	if (dup2(outfile, 1) == -1)
	{
		perror("pipex: dup2");
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	execute_cmd(argv[3], envp);
	exit(127);
}

static	int	ft_wait_pid(int *status, pid_t pid2)
{
	pid_t	wpid;

	while (1)
	{
		wpid = wait(&status[0]);
		if (wpid <= 0)
			break ;
		if (wpid == pid2)
		{
			if (WIFEXITED(status[0]))
				status[1] = WEXITSTATUS(status[0]);
			else if (WIFSIGNALED(status[0]))
				status[1] = 128 + WTERMSIG(status[0]);
		}
	}
	return (status[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status[2];

	status[1] = 0;
	if (argc != 5)
		return (write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37), 1);
	if (pipe(fd) == -1)
		return (perror("pipex: pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("pipex: fork"), 1);
	if (pid1 == 0)
		child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("pipex: fork"), 1);
	if (pid2 == 0)
		parent_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	return (ft_wait_pid(status, pid2));
}
