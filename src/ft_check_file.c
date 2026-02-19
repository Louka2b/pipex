/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:17:10 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/19 15:48:19 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path_part;
	char	*full_path;
	int		i;

	all_paths = ft_split(get_env_path(envp), ':');
	i = 0;
	while (all_paths[i])
	{
		path_part = ft_strjoin(all_paths[i], "/");
		full_path = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(full_path, X_OK) == 0)
		{
			free_tab(all_paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_tab(all_paths);
	return (NULL);
}

void	ft_parsing(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd1_args = ft_split(argv[2], ' ');
	if (pipex->cmd1_args && pipex->cmd1_args[0])
		pipex->cmd1_path = find_cmd_path(pipex->cmd1_args[0], envp);
	else
		pipex->cmd1_path = NULL;
	pipex->cmd2_args = ft_split(argv[3], ' ');
	if (pipex->cmd2_args && pipex->cmd2_args[0])
		pipex->cmd2_path = find_cmd_path(pipex->cmd2_args[0], envp);
	else
		pipex->cmd2_path = NULL;
	if (!pipex->cmd1_path)
		ft_printf("Error\nfirst cmd not found\n");
	if (!pipex->cmd2_path)
		ft_printf("Error\nseccond cmd not found\n");
}
