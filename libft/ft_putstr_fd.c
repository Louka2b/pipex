/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:35:39 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 16:30:28 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string ’s’ to the specified file
descriptor.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (i != ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
