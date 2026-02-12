/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:14:52 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/19 11:56:54 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function allocates a block of memory by
 * initializing all its bytes to the value 0. Although
 * relatively similar to the malloc function, two aspects
 *  differentiate them:
 *
 * @param count  allows you to specify the number of consecutive elements
 * to reserve in the memory block.
 * @param size  allows you to set the size (in number of bytes) of an element.
 * @return void* the sttring malloc with 0 value evrything
 */
void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	block;

	block = count * size;
	if (count && (size != (block / count)))
		return (NULL);
	str = (char *)malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
