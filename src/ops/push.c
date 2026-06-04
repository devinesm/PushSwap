/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/30 20:39:58 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	op_pa(t_stacks *s)
{
	t_node	*node;

	if (!s->b)
		return ;
	node = s->b;
	s->b = node->next;
	node->next = s->a;
	s->a = node;
	s->benchmarks.pa++;
	if (!s->benchmarks.count_only)
		write(1, "pa\n", 3);
}

void	op_pb(t_stacks *s)
{
	t_node	*node;

	if (!s->a)
		return ;
	node = s->a;
	s->a = node->next;
	node->next = s->b;
	s->b = node;
	s->benchmarks.pb++;
	if (!s->benchmarks.count_only)
		write(1, "pb\n", 3);
}
