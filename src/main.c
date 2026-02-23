/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:14:14 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/23 13:09:25 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (!pipex)
		return (NULL);
	if (argc != 5)
	{
		ft_printf("Error\nPipex need 4 args");
		return (0);
	}
	ft_parsing(pipex, argv, envp);
	free_all(pipex);
	return (0);
}
