/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/07 22:16:11 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

double	compute_disorder(t_node *stack)
{
	int		mistakes;
	int		total_pairs;
	t_node	*a;
	t_node	*b;

	mistakes = 0;
	total_pairs = 0;
	a = stack;
	while (a)
	{
		b = a->next;
		while (b)
		{
			total_pairs++;
			if (a->value > b->value)
				mistakes++;
			b = b->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
