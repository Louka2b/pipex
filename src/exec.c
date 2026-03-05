/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:38:54 by ldeplace          #+#    #+#             */
/*   Updated: 2026/03/03 16:13:42 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	path_error(char **cmd)
{
	write(2, "pipex: command not found: ", 26);
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, "\n", 1);
	free_tab(cmd);
	exit(127);
}

static void	relative_more(char **envp, char **cmd, char *path)
{	
	if (ft_strchr(cmd[0], '/'))
	{
		path = ft_strdup(cmd[0]);
		execve(path, cmd, envp);
		if (access(path, F_OK) == 0)
		{
			free_tab(cmd);
			free(path);
			exit(126);
		}
		free_tab(cmd);
		free(path);
		exit(127);
	}
	path = get_path(cmd[0], envp);
	if (!path)
		path_error(cmd);
	execve(path, cmd, envp);
	perror("pipex: execve");
	free_tab(cmd);
	if (access(path, X_OK) == 0)
	{
		exit_free(path);
	}
	free(path);
}

static	void	execute_cmd_relative(char *argv, char **envp)
{
	char	*path;
	char	**cmd;

	path = NULL;
	ft_check_space(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		exit(1);
	}
	relative_more(envp, cmd, path);
	exit(127);
}

static void	execute_cmd_absolute(char *argv, char **envp)
{
	char	**cmd;
	int		exit_code;

	ft_check_space(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		exit(1);
	}
	execve(cmd[0], cmd, envp);
	exit_code = 127;
	if (access(cmd[0], F_OK) == 0)
		exit_code = 126;
	free_tab(cmd);
	exit(exit_code);
}

void	execute_cmd(char *argv, char **envp)
{
	if (argv[0] == '/')
		execute_cmd_absolute(argv, envp);
	else
		execute_cmd_relative(argv, envp);
}
