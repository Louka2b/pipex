/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:24:05 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 20:49:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief isalnum() function in C programming language checks 
 * whether the given character is alphanumeric or not. isalnum() 
 * function defined in ctype.h header file. Alphanumeric: A 
 * character that is either a letter or a number.
 * 
 * @param c a character
 * @return int function returns some value. It always returns '8' for all 
 * characters except special characters like (#,@,% etc.). 
 * It will always return '0' for special characters.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
	{
		return (1);
	}
	return (0);
}
