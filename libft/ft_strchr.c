/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:32:08 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/21 14:22:25 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function searches for the first occurrence 
 * of the character passed as the second parameter in the string
 *  of characters specified via the first parameter.
 * 
 * @param s the string
 * @param c the character to search
 * @return char* Either the character you are looking for is present in the
 *  string, in which case a pointer to the first occurrence of
 *  the character will be returned. Or the character is not present
 *  in the string, in which case a NULL pointer will be returned.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
