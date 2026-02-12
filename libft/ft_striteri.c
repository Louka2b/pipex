/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/11/12 10:10:37 by marvin            #+#    #+#             */
/*   Updated: 2025/11/12 10:10:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ to each character of the
string passed as argument, passing its index as
the first argument. Each character is passed by
address to ’f’ so it can be modified if necessary.
 * 
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < ft_strlen(s))
		{
			(f)(i, &s[i]);
			i++;
		}
	}
}
