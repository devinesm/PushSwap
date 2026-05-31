/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:58:39 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/26 15:25:26 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if ((unsigned char) s1[index] != (unsigned char) s2[index]
			|| s1[index] == '\0')
			return ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
	}
	return (0);
}
