/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:11:54 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 19:31:18 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.

int	handle_c(va_list *args, int fmt)
{
	return (ft_putchar((char)va_arg(*args, int), fmt));
}

int	handle_s(va_list *args, int fmt)
{
	return (ft_putstr(va_arg(*args, char *), fmt));
}

int	handle_p(va_list *args, int fmt)
{
	return (ft_putptr(va_arg(*args, char *), fmt));
}

int	handle_d_i(va_list *args, int fmt)
{
	return (ft_putnbr(va_arg(*args, int), fmt));
}

int	handle_u(va_list *args, int fmt)
{
	return (ft_putnbr_unsigned(va_arg(*args, int), fmt));
}
