/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/08 12:55:43 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	op_sa(t_stacks *s)
{
	swap(&s->a);
	s->benchmarks.sa++;
	if (!s->benchmarks.count_only)
		write(1, "sa\n", 3);
}

void	op_sb(t_stacks *s)
{
	swap(&s->b);
	s->benchmarks.sb++;
	if (!s->benchmarks.count_only)
		write(1, "sb\n", 3);
}

void	op_ss(t_stacks *s)
{
	swap(&s->a);
	swap(&s->b);
	s->benchmarks.ss++;
	if (!s->benchmarks.count_only)
		write(1, "ss\n", 3);
}
