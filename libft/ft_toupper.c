/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:21:20 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 12:51:01 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function converts a lowercase letter to 
 * an uppercase letter. Note: the functions in this library
 *  only process pure ASCII characters. Accented letters
 *  will therefore not be treated as alphanumeric characters.
 * 
 * @param c the character to convert
 * @return int the character convert
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
