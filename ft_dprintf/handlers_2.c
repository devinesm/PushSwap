/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:11:54 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 19:32:05 by fiolivei         ###   ########.fr       */
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

int	handle_percent(va_list *args, int fmt)
{
	(void)args;
	return (ft_putchar('%', fmt));
}

int	handle_x_lower(va_list *args, int fmt)
{
	return (ft_puthex(va_arg(*args, unsigned long), "0123456789abcdef", fmt));
}

int	handle_x_upper(va_list *args, int fmt)
{
	return (ft_puthex(va_arg(*args, unsigned long), "0123456789ABCDEF", fmt));
}
