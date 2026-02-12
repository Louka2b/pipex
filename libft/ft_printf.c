/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:20:58 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/26 14:27:11 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	ft_putstr(char *s, size_t h)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		h += 6;
		return (h);
	}
	while (s[i])
	{
		h++;
		ft_putchar(s[i]);
		i++;
	}
	return (h);
}

static size_t	ft_putptr(void *ptr, size_t	h)
{
	unsigned long int	address;
	char				*hex;
	char				buffer[20];
	int					i;

	hex = "0123456789abcdef";
	address = (unsigned long int)ptr;
	i = 0;
	if (!ptr)
		return (ft_putstr("(nil)", h));
	h = h + 2;
	write(1, "0x", 2);
	if (address == 0)
	{
		return (h += ft_putchar('0'));
	}
	while (address > 0)
	{
		buffer[i++] = hex[address % 16];
		address /= 16;
	}
	while (i > 0)
		h += ft_putchar(buffer[--i]);
	return (h);
}

static size_t	ft_printf_cond(const char *s, int i, va_list ap, size_t	h)
{
	i++;
	if (s[i] == 'c')
		h += ft_putchar(va_arg(ap, int));
	else if (s[i] == 's')
		h = ft_putstr(va_arg(ap, char *), h);
	else if (s[i] == 'd' || s[i] == 'i')
		h += ft_putnbr(va_arg(ap, int), 0);
	else if (s[i] == 'u')
		h += ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), 0);
	else if (s[i] == 'x')
		h += ft_puthex_fd(va_arg(ap, unsigned int), 0);
	else if (s[i] == 'X')
		h += ft_puthexx_fd(va_arg(ap, unsigned int), 0);
	else if (s[i] == 'p')
		h = ft_putptr(va_arg(ap, void *), h);
	else if (s[i] == '%')
		h += ft_putchar('%');
	return (h);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	size_t	h;
	va_list	ap;

	i = 0;
	h = 0;
	va_start (ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			h = ft_printf_cond(s, i, ap, h);
			i++;
		}
		else
			h += ft_putchar(s[i]);
		i++;
	}
	va_end (ap);
	return (h);
}
