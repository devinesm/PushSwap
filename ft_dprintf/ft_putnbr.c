/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 19:31:28 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putnbr(int n, int fmt)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648", fmt));
	if (n < 0)
	{
		ft_putchar('-', fmt);
		n = -n;
		count = 1;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10, fmt);
	ft_putchar((n % 10) + '0', fmt);
	return (count + 1);
}

int	ft_putnbr_unsigned(unsigned int n, int fmt)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10, fmt);
	ft_putchar((n % 10) + '0', fmt);
	return (count + 1);
}
