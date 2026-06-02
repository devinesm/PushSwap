/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:58:40 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/06/02 16:40:52 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = ft_sqrt(size) * 2;
	if (chunk == 0)
		chunk = 1;
	return (chunk);
}

static void	push_chunks_to_b(t_stacks *s, int chunk_size)
{
	int	limit;

	limit = chunk_size;
	while (s->a != NULL)
	{
		if (s->a->index < limit)
		{
			op_pb(s);
			if (s->b->index < (limit - (chunk_size / 2)))
				op_rb(s);
		}
		else
			op_ra(s);
		if (stack_size(s->b) >= limit)
			limit += chunk_size;
	}
}

static int	get_max_pos(t_node *stack)
{
	t_node	*tmp;
	int		max_idx;
	int		max_pos;
	int		pos;

	tmp = stack;
	max_idx = -1;
	max_pos = 0;
	pos = 0;
	while (tmp != NULL)
	{
		if (tmp->index > max_idx)
		{
			max_idx = tmp->index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

static void	push_max_to_a(t_stacks *s)
{
	int	size;
	int	max_pos;

	while (s->b != NULL)
	{
		size = stack_size(s->b);
		max_pos = get_max_pos(s->b);
		if (max_pos <= size / 2)
		{
			while (max_pos > 0)
			{
				op_rb(s);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size)
			{
				op_rrb(s);
				max_pos++;
			}
		}
		op_pa(s);
	}
}

void	sort_medium(t_stacks *s)
{
	int	size;
	int	chunk_size;

	size = stack_size(s->a);
	assign_index(s);
	chunk_size = get_chunk_size(size);
	push_chunks_to_b(s, chunk_size);
	push_max_to_a(s);
}
