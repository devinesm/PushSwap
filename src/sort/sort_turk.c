/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:12:16 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 16:22:17 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	get_scenario(t_cost *cost, int *scenarios)
{
	int	i;

	i = 1;
	cost->total = scenarios[BOTH_UP];
	cost->scenario = BOTH_UP;
	while (i < 4)
	{
		if (scenarios[i] < cost->total)
		{
			cost->total = scenarios[i];
			cost->scenario = (t_scenario)i;
		}
		i++;
	}
}

static t_cost	compute_cost(t_node *node_a, int pos_a, t_stacks *s)
{
	t_cost	cost;
	int		size_a;
	int		size_b;
	int		scenarios[4];

	size_a = stack_size(s->a);
	size_b = stack_size(s->b);
	cost.ra = pos_a;
	cost.rra = size_a - pos_a;
	cost.rb = target_position_in_b(node_a->value, s->b);
	cost.rrb = size_b - cost.rb;
	scenarios[BOTH_UP] = max_int(cost.ra, cost.rb) + 1;
	scenarios[BOTH_DOWN] = max_int(cost.rra, cost.rrb) + 1;
	scenarios[A_UP_B_DOWN] = cost.ra + cost.rrb + 1;
	scenarios[A_DOWN_B_UP] = cost.rra + cost.rb + 1;
	get_scenario(&cost, scenarios);
	return (cost);
}

static t_node	*find_cheapest(t_stacks *s, t_cost *out_cost)
{
	t_cost	tmp_cost;
	t_node	*a;
	t_node	*out;
	int		i;

	i = 0;
	a = s->a;
	out = a;
	*out_cost = compute_cost(a, i, s);
	a = a->next;
	while (a)
	{
		tmp_cost = compute_cost(a, ++i, s);
		if (tmp_cost.total < out_cost->total)
		{
			*out_cost = tmp_cost;
			out = a;
		}
		a = a->next;
	}
	return (out);
}

void	sort_turk(t_stacks *s)
{
	t_cost	cost;

	if (stack_size(s->a) <= 3)
		return (sort_three(s));
	if (stack_size(s->a) <= 5)
		return (sort_five(s));
	while (stack_size(s->a) > 3)
	{
		find_cheapest(s, &cost);
		execute_move(&cost, s);
	}
	sort_three(s);
	push_b_to_a(s);
	rotate_min_to_top(s);
}
