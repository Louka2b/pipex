/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:14:58 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 20:45:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief  function returns a non-zero value (equivalent to bo
 * olean true) if a character is an alphabet letter (a-z).
 * 
 * @param c Required. The ASCII value of a character or an 
 * actual character
 * @return int An int value which is non-zero 
 * (equivalent to boolean true) if the character is a letter.
 **/
int	ft_isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
