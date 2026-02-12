/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:25:45 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 13:00:06 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function compares two strings and determines if the 
 * first is less than, equal to, or greater than the second. The
 *  comparison is performed in lexicographical order (and therefore 
 * takes into account the ASCII values ​​of the characters being compared).
 *  However, the comparison will be limited to the first length characters.
 * 
 * @param s1 the first string of characters to compare.
 * @param s2 the second string of characters to compare.
 * @param n the maximum number (an unsigned integer) of characters to compare.
 * @return int Three distinct cases must be considered. Either the
 *  two strings are equal: in this case, a null value will be returned.
 *  Or the first string is shorter than the second (in lexicographical
 *  order): in this case, a negative value will be returned. Or the first
 *  string is longer than the second: in this last case, a positive value 
 * will be returned. In all cases, the absolute value will indicate the
 *  position of the first character that produces the result.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
