/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:11:06 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/23 15:58:44 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= 10;
		len += 2;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nl;
	char	*nbr;
	size_t	index;

	nl = n;
	len = get_len(n);
	nbr = malloc(len + 1);
	index = 0;
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (nl < 0)
	{
		nbr[index] = '-';
		nl *= -1;
		index++;
	}
	while (index < len)
	{
		nbr[--len] = (nl % 10) + '0';
		nl /= 10;
	}
	return (nbr);
}
