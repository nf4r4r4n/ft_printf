/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:12:45 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 19:13:48 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
/* ----- SPECS ----- */
# ifndef SPECS
#  define SPECS "cspdiuxX%"
# endif
/* ----- INT_MIN ----- */
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
/* ----- INT_MAX ----- */
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
/* ----- LONG_MIN ----- */
# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775808
# endif
/* ----- LONG_MAX ----- */
# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif
/* ----- UINT MAX ----- */
# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif
/* ----- PROTOTYPES ----- */
char	*ft_strchr(const char *s, char c);
void	ft_putc(char c, int *len);
void	ft_puts(char *s, int *len);
void	ft_putdi(int nb, int *len);
void	ft_putu(unsigned int nb, int *len);
int		ft_printf(const char *fmt, ...);

#endif
