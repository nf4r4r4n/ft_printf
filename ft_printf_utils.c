/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:12:55 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 20:04:04 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

void	ft_putu(unsigned int nb, int *len)
{
	if (nb == UINT_MAX)
	{
		ft_puts("4294967295", len);
		return ;
	}
	if (nb > 9)
	{
		ft_putu(nb / 10, len);
		ft_putu(nb % 10, len);
	}
	else
		ft_putc(nb + '0', len);
}

void	ft_putx(unsigned int nb, int *len, t_bool is_low)
{
	if (nb > 15)
	{
		ft_putx(nb / 16, len, is_low);
		ft_putx(nb % 16, len, is_low);
	}
	else
	{
		if (is_low == TRUE)
			ft_putc(HEXA_NB[nb], len);
		else
			ft_putc(HEXA_NB_UP[nb], len);
	}
}

static void	ft_putxl(unsigned long nb, int *len)
{
	if (nb > 15)
	{
		ft_putxl(nb / 16, len);
		ft_putxl(nb % 16, len);
	}
	else
		ft_putc(HEXA_NB[nb], len);
}

void	ft_putp(unsigned long ptr, int *len)
{
	unsigned long	nptr;

	if (!ptr)
	{
		ft_puts("(nil)", len);
		return ;
	}
	nptr = (unsigned long)ptr;
	ft_puts("0x", len);
	ft_putxl(nptr, len);
}
