/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:14:14 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/19 15:48:27 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	if (argc != 5)
	{
		ft_printf("Error\nPipex need 4 args");
		return (0);
	}
	ft_parsing(&pipex, argv, envp);
	return (0);
}
