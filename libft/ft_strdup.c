/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:08:37 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/21 14:23:47 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function allows you to duplicate a string of characters.
 * 
 * @param src allows you to define the address of the string to be duplicated.
 * @return char* if there is enough memory to produce the new string, the 
 * function returns the address of the duplicated string. Otherwise, a 
 * null pointer will be returned.
 */
char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(src);
	j = 0;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (src[j])
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
