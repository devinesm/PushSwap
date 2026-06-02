/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:24:00 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/05/31 17:24:00 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	assign_index(t_stacks *s)
{
	t_node	*curr;
	t_node	*cmp;
	int		count;

	curr = s->a;
	while (curr)
	{
		count = 0;
		cmp = s->a;
		while (cmp)
		{
			if (cmp->value < curr->value)
				count++;
			cmp = cmp->next;
		}
		curr->index = count;
		curr = curr->next;
	}
}

static int	get_max_bits(t_stacks *s)
{
	int	size;
	int	max_index;
	int	max_bits;

	size = stack_size(s->a);
	max_index = size - 1;
	max_bits = 0;
	while (max_index > 0)
	{
		max_bits++;
		max_index = max_index >> 1;
	}
	return (max_bits);
}

static void	execute_radix(t_stacks *s, int max_bits)
{
	int		size;
	int		i;
	int		j;
	int		atual_bit;
	t_node	*top;

	i = 0;
	size = stack_size(s->a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			top = s->a;
			atual_bit = (top->index >> i) & 1;
			if (atual_bit == 1)
				op_ra(s);
			else
				op_pb(s);
			j++;
		}
		while (s->b)
			op_pa(s);
		i++;
	}
}

void	sort_complex(t_stacks *s)
{
	int	max_bits;

	assign_index(s);
	max_bits = get_max_bits(s);
	execute_radix(s, max_bits);
}
