/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:46 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 17:58:33 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_fmt(va_list args, char spec, int *len)
{
	if (spec == 'c')
		ft_putc(va_arg(args, int), len);
	else if (spec == 's')
		ft_puts(va_arg(args, char *), len);
	else if (spec == 'p')
	{}
	else if (spec == 'd')
		ft_putdi(va_arg(args, int), len);
	else if (spec == 'i')
		ft_putdi(va_arg(args, int), len);
	else if (spec == 'u')
	{}
	else if (spec == 'x')
	{}
	else if (spec == 'X')
	{}
	else if (spec == '%')
		ft_putc('%', len);
}

void	ft_putc(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_puts(char *s, int *len)
{
	unsigned int	size;

	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	size = 0;
	while (s[size])
		size++;
	write(1, s, size);
	*len += size;
}

void	ft_putdi(int nb, int *len)
{
	if (nb == INT_MIN)
	{
		ft_puts("-2147483648", len);
		return ;
	}
	if (nb == INT_MAX)
	{
		ft_puts("2147483647", len);
		return ;
	}
	if (nb < 0)
	{
		ft_putc('-', len);
		ft_putdi(-nb, len);
	}
	else if (nb > 9)
	{
		ft_putdi(nb / 10, len);
		ft_putdi(nb % 10, len);
	}
	else
		ft_putc(nb + '0', len);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && ft_strchr(SPECS, '%') != 0)
		{
			ft_handle_fmt(args, fmt[1], &len);
			fmt += 2;
		}
		else
			ft_putc(*fmt++, &len);
	}
	va_end(args);
	return (len);
}
