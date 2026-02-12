/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:17:15 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 13:14:07 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		||c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

/**
 * @brief This function allows you to transform a string of
 *  characters, representing an integer value, into a numeric
 *  value of type int . The term atoi is an acronym meaning:
 *  A SCII to nteger.
 * 
 * @param str this parameter contains the string of characters
 *  to be converted into an int data type.
 * @return int the converted number
 */
int	ft_atoi(const char *str)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str++ - 48);
	}
	return (result * sign);
}
