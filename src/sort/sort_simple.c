/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:12:16 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/31 15:15:37 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_simple(t_stacks *s)
{
	int	size;
	int	min_pos;

	size = stack_size(s->a);
	if (size == 2)
	{
		if (s->a->value > s->a->next->value)
			op_sa(s);
		return ;
	}
	while (size > 3 && !is_sorted(s->a))
	{
		min_pos = find_position_of_min(s->a);
		if (min_pos <= size / 2)
			while (min_pos-- > 0)
				op_ra(s);
		else
			while (min_pos++ < size)
				op_rra(s);
		op_pb(s);
		size--;
	}
	sort_three(s);
	while (s->b)
		op_pa(s);
}
