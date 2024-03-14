/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:12:45 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/14 20:10:45 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

/* ----- TYPES ----- */
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/* ----- HEXA_NB ----- */
# ifndef HEXA_NB
#  define HEXA_NB "0123456789abcdef"
# endif

/* ----- HEXA_NB_UP ----- */
# ifndef HEXA_NB_UP
#  define HEXA_NB_UP "0123456789ABCDEF"
# endif

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

/* ----- UINT MAX ----- */
# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif

/* ----- ULONG_MAX -----*/
# ifndef ULONG_MAX
#  define ULONG_MAX 18446744073709551615ul
# endif

/* ----- PROTOTYPES ----- */
char	*ft_strchr(const char *s, char c);
void	ft_putc(char c, int *len);
void	ft_puts(char *s, int *len);
void	ft_putdi(int nb, int *len);
void	ft_putu(unsigned int nb, int *len);
void	ft_putx(unsigned int nb, int *len, t_bool is_low);
void	ft_putp(unsigned long ptr, int *len);
int		ft_printf(const char *fmt, ...);

#endif
