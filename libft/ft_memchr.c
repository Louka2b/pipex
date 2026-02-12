/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:35:29 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 16:19:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the first occurrence of a value of type int , 
 * but interpreted as char , in a block of memory. Since we are dealing
 *  with a block of memory and not an AZT string (with a zero terminal),
 *  we must also specify the size to the function. of the memory block in
 *  which to perform the search.
 * 
 * @param s a pointer indicating the address of the memory block to 
 * use for the search.
 * @param c the numeric code of the byte to search for in the block.
 * @param n  indicates the size of the memory block in which to perform 
 * the search.
 * @return void* If the function found the character being searched
 *  for, it returns a pointer to its first occurrence. If not, the function 
 * returns NULL .
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
