/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:38:54 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/25 18:09:55 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	execute_cmd_absolute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		exit(1);
	}
	path = ft_strdup(cmd[0]);
	execve(cmd[0], cmd, envp);
	perror("pipex: execve");
	free_tab(cmd);
	if (access(path, X_OK) == 0)
		free(path);
	exit(126);
	free(path);
	exit(127);
}

static void	path_error(char **cmd)
{
	write(2, "pipex: command not found: ", 26);
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, "\n", 1);
	free_tab(cmd);
	exit(127);
}

static void	execute_cmd_relative(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	ft_check_space(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		exit(1);
	}
	path = get_path(cmd[0], envp);
	if (!path)
		path_error(cmd);
	execve(path, cmd, envp);
	if (access(path, X_OK) == 0)
		exit(126);
	free(path);
	free_tab(cmd);
	exit(127);
}

void	execute_cmd(char *argv, char **envp)
{
	if (argv[0] == '/')
		execute_cmd_absolute(argv, envp);
	else
		execute_cmd_relative(argv, envp);
}
