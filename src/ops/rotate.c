/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	op_ra(t_stacks *s)
{
	rotate(&s->a);
	s->benchmarks.ra++;
	if (!s->benchmarks.count_only)
		write(1, "ra\n", 3);
}

void	op_rb(t_stacks *s)
{
	rotate(&s->b);
	s->benchmarks.rb++;
	if (!s->benchmarks.count_only)
		write(1, "rb\n", 3);
}

void	op_rr(t_stacks *s)
{
	rotate(&s->a);
	rotate(&s->b);
	s->benchmarks.rr++;
	if (!s->benchmarks.count_only)
		write(1, "rr\n", 3);
}
