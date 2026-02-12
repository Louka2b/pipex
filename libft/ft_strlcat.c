/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:43:39 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 15:43:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief copy and concatenate strings respectively.
 * 
 * @param dst the destination
 * @param src the source 
 * @param size the size 
 * @return size_t return the total length of the string they tried to create
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	count;
	size_t	src_size;

	count = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (size + src_size);
	while ((src[count] != '\0') && (count + dest_size < size - 1))
	{
		dst[dest_size + count] = src[count];
		count++;
	}
	dst[dest_size + count] = '\0';
	if (dest_size < size)
		return (dest_size + src_size);
	return (size + src_size);
}
