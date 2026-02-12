/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/11/11 15:34:16 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 15:34:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief check if the given character is a numeric digit or not
 *
 * @param c Character which we have to check.
 * @return int If the given character represents a numeric digit,
	it returns true.
Otherwise, it returns false.
 */
int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}
