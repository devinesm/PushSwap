/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:05:13 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 11:09:21 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*byte_ptr;
	unsigned char	byte_value;

	index = 0;
	byte_ptr = (unsigned char *)s;
	byte_value = (unsigned char)c;
	while (index < n)
	{
		if (byte_ptr[index] == byte_value)
			return ((void *)&byte_ptr[index]);
		index++;
	}
	return (NULL);
}
