/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:38:28 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 20:50:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Character classification macro.

These functions depend on the LC_CTYPE

isascii is a macro that classifies ASCII-coded integer values by table lookup
. It is a predicate returning nonzero for true and 0 for false.
 * 
 * @param c a character
 * @return int isascii returns nonzero if c is in the range 0 to 127 (0x00-0x7F).

iswascii returns nonzero if c is is a wide-character representation
 of an ASCII character.

Each of these routines returns 0 if c does not satisfy the test condition.
 */
int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}
