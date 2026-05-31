/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:46:47 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/26 15:18:50 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (!src && !dest)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		index = n;
		while (index > 0)
		{
			index--;
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		}
	}
	return (dest);
}

/*
 * ft_memmove guarantees a safe memory copy,
 * even when src and dest overlap
 *
 * Problem Example: I want to move 123 one space to the right.
 * 
 * str[] = "12345"
 *
 * If I wanted to move from left to right (normal way),
 * I would pick the number "1" (index 0) and write in
 * the next position (index 1 -> "11345"). Then, I need to
 * take the next number ("2"), but it does not exist anymore.
 * So, at the end of the function, the result would be "11115".
 *
 * Solution: As the dest is after src (dest > src), the function
 * detects the danger and copys backwards
 */
