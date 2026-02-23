/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:24:37 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/23 13:02:31 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->cmd2_args)
			free_tab(pipex->cmd2_args);
		if (pipex->cmd1_args)
			free_tab(pipex->cmd1_args);
		if (pipex->cmd1_path)
			free(pipex->cmd1_path);
		if (pipex->cmd2_path)
			free(pipex->cmd2_path);
		if (pipex->infile)
			free(pipex->infile);
		if (pipex->outfile)
			free(pipex->outfile);
		free(pipex);
	}
}

void	error_exit(char *msg, int status)
{
	perror(msg);
	exit(status);
}