/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:09:24 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/29 19:11:38 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_dprintf(int fd, const char *format, ...);

typedef int		(*t_handler)(va_list *, int);

typedef struct s_dispatch
{
	char		spec;
	t_handler	fn;
}			t_dispatch;

int			handle_d_i(va_list *args, int fmt);
int			handle_s(va_list *args, int fmt);
int			handle_c(va_list *args, int fmt);
int			handle_u(va_list *args, int fmt);
int			handle_x_upper(va_list *args, int fmt);
int			handle_x_lower(va_list *args, int fmt);
int			handle_p(va_list *args, int fmt);
int			handle_percent(va_list *args, int fmt);

int			ft_putchar(char c, int fmt);
int			ft_putnbr(int n, int fmt);
int			ft_putstr(char *s, int fmt);
int			ft_putnbr_unsigned(unsigned int n, int fmt);
int			ft_puthex(unsigned long n, char *base, int fmt);
int			ft_putptr(void *p, int fmt);
#endif
