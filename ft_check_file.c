/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:17:10 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/12 13:23:00 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_file(char **argv)
{
	int	*i;

	i = (int *)malloc(2 8 sizeof(int));
	if (!i)
		exit(0);
	i[0] = open(argv[1]);
	i[1] = open(argv[1]);
	if (i[0] == 0)
		ft_add_file();
	if (i[1] == 0)
		ft_add_file();
	close(i[0]);
	close(i[1]);
	free(i);
}
