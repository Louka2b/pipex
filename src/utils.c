/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:39:00 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/25 11:39:17 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			free_tab(paths);
			return (full_path);
		}
		free(full_path);
	}
	free_tab(paths);
	return (NULL);
}

void	ft_check_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
	{
		write(2, "pipex: command not found\n", 25);
		exit(127);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}