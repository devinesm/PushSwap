/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:04:16 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/05/31 17:04:16 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_three_cases(t_stacks *s, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		op_sa(s);
	else if (a > b && b > c)
	{
		op_sa(s);
		op_rra(s);
	}
	else if (a > b && b < c && a > c)
		op_ra(s);
	else if (a < b && b > c && a < c)
	{
		op_sa(s);
		op_ra(s);
	}
	else if (a < b && b > c && a > c)
		op_rra(s);
}

void	sort_three(t_stacks *s)
{
	int	size;
	int	a;
	int	b;
	int	c;

	size = stack_size(s->a);
	if (size < 2)
		return ;
	if (size == 2)
	{
		if (s->a->value > s->a->next->value)
			op_sa(s);
		return ;
	}
	a = s->a->value;
	b = s->a->next->value;
	c = s->a->next->next->value;
	sort_three_cases(s, a, b, c);
}

int	find_position_of_min(t_node *a)
{
	t_node	*min;
	int		pos;

	pos = 0;
	min = find_min(a);
	while (a->value > min->value)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
