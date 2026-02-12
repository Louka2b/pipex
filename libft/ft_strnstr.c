/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:40:55 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 14:03:31 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The  strstr()  function locates the first occurrence of the null-termi-
 * nated string little in the null-terminated string big.
 * 
 * @param big 
 * @param little
 * @param len
 * @return char* If little is an empty string, big is returned; if little	
 * occurs nowhere
 * in big, NULL is returned; otherwise a pointer to	the first character of
 * the first occurrence of little is returned.

 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] != '\0' && j + i < len)
			{
				if (big[i + j] == little[j] && little[j + 1] == '\0')
					return ((char *)&big[i]);
				else if (big[i + j] != little[j])
					break ;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
