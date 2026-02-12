/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:14:14 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/12 13:16:57 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Error\nPipex need 4 args");
		return (0);
	}
	ft_check_file(argv);
	return (0);
}
