/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:51:33 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 21:09:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a block of memory with a specific byte value.
 *
 * This function writes the byte value `c` into the first `n` bytes
 * of the memory area pointed to by `str`.
 *
 * It is commonly used to initialize memory with a known value,
 * such as zeroing out a buffer or setting all bytes to a specific pattern.
 *
 * @param str Pointer to the memory area to fill.
 * @param c Byte value to set (interpreted as an unsigned char).
 * @param n Number of bytes to write.
 * @return void* Returns the original pointer `str`.
 */
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*buffer;

	count = 0;
	buffer = str;
	while (count < n)
	{
		buffer[count] = c;
		count++;
	}
	return (buffer);
}
