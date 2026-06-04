/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:12:16 by fiolivei          #+#    #+#             */
/*   Updated: 2026/06/04 13:47:57 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate_a_to_target(t_stacks *s, int target)
{
	int	size;

	size = stack_size(s->a);
	if (target <= size / 2)
		while (target-- > 0)
			op_ra(s);
	else
		while (target++ < size)
			op_rra(s);
}

// v[0]=pos, v[1]=cheapest_pos, v[2]=min_cost
static int	get_cheapest_pos(t_stacks *s)
{
	t_node	*t;
	int		v[3];
	int		c_a;
	int		c_b;

	t = s->a;
	v[0] = 0;
	v[1] = 0;
	v[2] = 2147483647;
	while (t)
	{
		c_a = calc_cost(v[0], stack_size(s->a));
		c_b = calc_cost(get_target_b(s->b, t->index), stack_size(s->b));
		if (c_a + c_b < v[2])
		{
			v[2] = c_a + c_b;
			v[1] = v[0];
		}
		v[0]++;
		t = t->next;
	}
	return (v[1]);
}

static void	move_cheapest(t_stacks *s, int p_a)
{
	int		p_b;
	int		tmp_pos;
	t_node	*tmp;

	tmp = s->a;
	tmp_pos = p_a;
	while (tmp_pos-- > 0)
		tmp = tmp->next;
	p_b = get_target_b(s->b, tmp->index);
	rotate_a_to_target(s, p_a);
	if (p_b <= stack_size(s->b) / 2)
		while (p_b-- > 0)
			op_rb(s);
	else
		while (p_b++ < stack_size(s->b))
			op_rrb(s);
	op_pb(s);
}

void	sort_simple(t_stacks *s)
{
	assign_index(s);
	if (stack_size(s->a) > 3)
		op_pb(s);
	if (stack_size(s->a) > 3)
		op_pb(s);
	while (stack_size(s->a) > 3 && !is_sorted(s->a))
		move_cheapest(s, get_cheapest_pos(s));
	if (!is_sorted(s->a))
		sort_three(s);
	while (s->b)
	{
		rotate_a_to_target(s, get_target_a(s->a, s->b->index));
		op_pa(s);
	}
	rotate_a_to_target(s, get_min_pos(s->a));
}
