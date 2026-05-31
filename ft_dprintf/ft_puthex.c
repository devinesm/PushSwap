/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:45:14 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 19:31:30 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_puthex(unsigned long n, char *base, int fmt)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base, fmt);
	ft_putchar(base[(n % 16)], fmt);
	return (count + 1);
}

int	ft_putptr(void *p, int fmt)
{
	int	count;

	if (p == NULL)
		return (ft_putstr("(nil)", fmt));
	count = ft_putstr("0x", fmt);
	count += ft_puthex((unsigned long)p, "0123456789abcdef", fmt);
	return (count);
}
