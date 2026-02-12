/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:06:09 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 16:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function compares the contents of two memory blocks 
 *  specified by the first two parameters. The third parameter, size,
 *  specifies the number of bytes to compare between the two blocks. 
 * The bytes of the two blocks are compared two bytes at a time. As 
 * long as the two bytes being compared are equal, the function moves
 *  on to the next two. If the two bytes being compared are different,
 *  then the function will return which of the two blocks is smaller in
 *   terms of content.
 * 
 * @param ptr1 allows you to specify the address of the first memory 
 * block to compare.
 * @param ptr2 allows you to specify the address of the second memory 
 * block to compare.
 * @param num indicates the maximum number of bytes to compare.
 * @return int Three cases are possible in terms of return value.
 *  Either the return value is negative: in this case, the first
 *  differing byte between the two blocks is smaller in the first
 *  block. Or the return value is zero: in this case, the two blocks
 *  have strictly identical contents. Finally, if the return value
 *  is positive: in this case, the first differing byte between the 
 * two blocks is larger in the first block.
 */
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			count;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	count = 0;
	buffer1 = (unsigned char *)ptr1;
	buffer2 = (unsigned char *)ptr2;
	while (count != num)
	{
		if (buffer1[count] != buffer2[count])
			return (buffer1[count] - buffer2[count]);
		count++;
	}
	return (0);
}
