/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:01:10 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/26 15:29:24 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index2;

	if (*little == '\0')
		return ((char *)big);
	index = 0;
	while (big[index] != '\0' && index < len)
	{
		index2 = 0;
		while (little[index2] != '\0'
			&& big[index + index2] == little[index2]
			&& (index + index2) < len)
			index2++;
		if (little[index2] == '\0')
			return ((char *)(big + index));
		index++;
	}
	return (NULL);
}
