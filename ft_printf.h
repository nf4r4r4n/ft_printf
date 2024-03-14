/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:12:45 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 16:04:54 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# ifndef SPECS
#  define SPECS "cspdiuxX%"
# endif

char	*ft_strchr(const char *s, char c);
void	ft_putc(char c, int *len);
void	ft_puts(char *s, int *len);
int		ft_printf(const char *fmt, ...);

#endif
