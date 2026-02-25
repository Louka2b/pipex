/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:38:54 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/25 11:38:55 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void execute_cmd_absolute(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		exit(1);
	}
	execve(cmd[0], cmd, envp);
	perror("pipex: execve");
	free_tab(cmd);
	exit(127);
}

static void execute_cmd_relative(char *argv, char **envp)
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
	{
		write(2, "pipex: command not found: ", 26);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		free_tab(cmd);
		exit(127);
	}
	execve(path, cmd, envp);
	free(path);
	free_tab(cmd);
	exit(127);
}

void	execute_cmd(char *argv, char **envp)
{
	if (ft_strchr(argv, '/'))
		execute_cmd_absolute(argv, envp);
	else
		execute_cmd_relative(argv, envp);
}
