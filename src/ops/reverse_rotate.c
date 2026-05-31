/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*penultimate;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	penultimate = *stack;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	op_rra(t_stacks *s)
{
	reverse_rotate(&s->a);
	s->benchmarks.rra++;
	write(1, "rra\n", 4);
}

void	op_rrb(t_stacks *s)
{
	reverse_rotate(&s->b);
	s->benchmarks.rrb++;
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stacks *s)
{
	reverse_rotate(&s->a);
	reverse_rotate(&s->b);
	s->benchmarks.rrr++;
	write(1, "rrr\n", 4);
}
