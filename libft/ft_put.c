/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:47:56 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/26 14:27:26 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthexx_fd(unsigned int nb, size_t h)
{
	if (nb < 16)
	{
		if (nb < 10)
			h += ft_putchar(nb + '0');
		else
			h += ft_putchar((nb + 'A' - 10));
	}
	if (nb >= 16)
	{
		h = ft_puthexx_fd(nb / 16, h);
		h = ft_puthexx_fd(nb % 16, h);
	}
	return (h);
}

size_t	ft_puthex_fd(unsigned int nb, size_t h)
{
	if (nb < 16)
	{
		if (nb < 10)
			h += ft_putchar('0' + nb);
		else
			h += ft_putchar('a' + nb - 10);
		return (h);
	}
	h = ft_puthex_fd(nb / 16, h);
	h = ft_puthex_fd(nb % 16, h);
	return (h);
}

size_t	ft_putnbr_unsigned_fd(unsigned int nb, size_t h)
{
	if (nb <= 9)
	{
		h += ft_putchar(nb + '0');
	}
	if (nb >= 10)
	{
		h = ft_putnbr_unsigned_fd(nb / 10, h);
		h = ft_putnbr_unsigned_fd(nb % 10, h);
	}
	return (h);
}

size_t	ft_putnbr(int nb, size_t h)
{
	if (nb == -2147483648)
	{
		h = h + 11;
		write(1, "-2147483648", 11);
		return (h);
	}
	if (nb < 0)
	{
		h += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		h += ft_putchar(nb + '0');
	}
	if (nb >= 10)
	{
		h = ft_putnbr(nb / 10, h);
		h = ft_putnbr(nb % 10, h);
	}
	return (h);
}
