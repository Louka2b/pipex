/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:20:25 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/24 18:30:38 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	free_tab(paths);
	return (NULL);
}

void	execute_cmd(char *argv, char **envp)
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
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_tab(cmd);
		perror("pipex: command not found");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("pipex: execve");
		free(path);
		free_tab(cmd);
		exit(1);
	}
}