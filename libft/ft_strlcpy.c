/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:10:18 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 12:49:50 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief the ft_strlcpy() functions copy and concatenate strings respectively.
 * 
 * @param dest the destination
 * @param src the source
 * @param size the size 
 * @return size_t the length of src.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] != '\0' && count < (size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}
