/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:18:34 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/06/04 13:50:41 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	calc_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	get_max_pos(t_node *stack)
{
	t_node	*tmp;
	int		max_idx;
	int		max_pos;
	int		pos;

	tmp = stack;
	max_idx = -1;
	max_pos = 0;
	pos = 0;
	while (tmp)
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

int	get_min_pos(t_node *stack)
{
	t_node	*tmp;
	int		min_idx;
	int		min_pos;
	int		pos;

	tmp = stack;
	min_idx = 2147483647;
	min_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < min_idx)
		{
			min_idx = tmp->index;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

int	get_target_b(t_node *stack_b, int index_a)
{
	t_node	*tmp;
	int		t_pos;
	int		t_idx;
	int		pos;

	tmp = stack_b;
	t_pos = 0;
	t_idx = -1;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < index_a && tmp->index > t_idx)
		{
			t_idx = tmp->index;
			t_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (t_idx == -1)
		return (get_max_pos(stack_b));
	return (t_pos);
}

int	get_target_a(t_node *stack_a, int index_b)
{
	t_node	*tmp;
	int		t_pos;
	int		t_idx;
	int		pos;

	tmp = stack_a;
	t_pos = 0;
	t_idx = 2147483647;
	pos = 0;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < t_idx)
		{
			t_idx = tmp->index;
			t_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (t_idx == 2147483647)
		return (get_min_pos(stack_a));
	return (t_pos);
}
