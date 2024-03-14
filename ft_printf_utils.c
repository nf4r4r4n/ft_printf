/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:12:55 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 19:11:56 by nfararan         ###   ########.fr       */
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
