/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:29:08 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 16:30:00 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the character ’c’ to the specified file
descriptor.
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write.`
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
