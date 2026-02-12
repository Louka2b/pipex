/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:55:47 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 12:44:33 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function allows copying a block of memory 
 * specified by the source parameter, and whose size is 
 * specified via the parameter size , in a new location
 *  designated by the destination parameter. It is 
 * understood that it is your responsibility to allocate
 *  enough memory for the destination block so that it 
 * can contain all the data.
 * 
 * @param dest allows you to specify the address of 
 * the memory block that will receive the data to be copied.
 *  You must pre-allocate this memory block (likely using the 
 * malloc function).
 * @param src allows you to define the address of the 
 * memory block to be duplicated.
 * @param n indicates the number of bytes to duplicate.
 * @return void* The function returns the address of the destination 
 * memory block.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*buffer1;
	char	*buffer2;
	size_t	count;

	buffer1 = (char *)src;
	buffer2 = dest;
	count = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (count < n)
	{
		buffer2[count] = buffer1[count];
		count++;
	}
	return (dest);
}
