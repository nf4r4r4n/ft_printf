/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:46 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 16:20:31 by nfararan         ###   ########.fr       */
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
	{}
	else if (spec == 'i')
	{}
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
