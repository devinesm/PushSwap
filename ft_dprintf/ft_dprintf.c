/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:21:56 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/29 19:11:32 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	put_formated_char(const char *format, va_list *args, int fmt)
{
	static t_dispatch	dispatch[] = {{'d', handle_d_i}, {'i', handle_d_i},
	{'s', handle_s}, {'c', handle_c}, {'u', handle_u}, {'x',
		handle_x_lower}, {'X', handle_x_upper}, {'p', handle_p}, {'%',
		handle_percent}, {0, NULL}};
	int					i;
	int					count;

	count = 0;
	i = 0;
	while (dispatch[i].spec)
	{
		if (dispatch[i].spec == *(format))
		{
			count += dispatch[i].fn(args, fmt);
			break ;
		}
		i++;
	}
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += put_formated_char(format, &args, fd);
		}
		else
		{
			count += ft_putchar(*format, fd);
		}
		format++;
	}
	va_end(args);
	return (count);
}
