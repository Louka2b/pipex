/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:47:01 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 21:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * This function writes zero bytes (`'\0'`) into the first `n` bytes
 * of the memory area pointed to by `s`.
 *
 * It is typically used to clear memory before use, ensuring that
 * all values are initialized to zero.
 *
 * @param s Pointer to the memory area to clear.
 * @param n Number of bytes to set to zero.
 * @return void Does not return a value.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
