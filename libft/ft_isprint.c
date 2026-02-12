/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:42:59 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 20:52:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if c is a printable character
 * 
 * @param c a character
 * @return int Non-zero value if the character can be printed, zero otherwise.
 */
int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	else
		return (0);
}
