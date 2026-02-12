/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:30:47 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 12:55:23 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function converts an uppercase letter to a lowercase letter.
 *  Note: the functions in this library only process pure ASCII characters.
  Accented letters will therefore not be treated as alphanumeric characters.
 * 
 * @param c the character to convert
 * @return int the character convert
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
