/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:34:01 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 16:28:28 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.
 * 
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @return char* The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	cur;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	cur = 0;
	while (s[cur])
	{
		result[cur] = f(cur, s[cur]);
		cur++;
	}
	result[cur] = 0;
	return (result);
}
