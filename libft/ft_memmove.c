/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:13 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 12:44:16 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_memmove() function copies count bytes from src to dest
 *  . This function allows copying objects that may overlap as if src 
 * were first copied into a temporary array.
 * 
 * @param dest  allows you to specify the address of the memory 
 * block that should receive the data to be copied.
 * @param src allows you to define the address of the memory
 * block to be duplicated.
 * @param n indicates the number of bytes to duplicate.
 * @return void* The function returns the address of the destination
 *  memory block.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
