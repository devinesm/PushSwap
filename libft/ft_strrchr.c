/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:47:44 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 11:07:26 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	index;

	index = (long int)ft_strlen(s);
	while (index >= 0)
	{
		if ((unsigned char)s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
