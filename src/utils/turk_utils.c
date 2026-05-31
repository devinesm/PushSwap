/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:58:35 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 16:18:11 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	execute_both_up(t_cost *c, t_stacks *s)
{
	int	rr_count;
	int	extra_a;
	int	extra_b;

	rr_count = min_int(c->ra, c->rb);
	extra_a = c->ra - rr_count;
	extra_b = c->rb - rr_count;
	while (rr_count--)
		op_rr(s);
	while (extra_a--)
		op_ra(s);
	while (extra_b--)
		op_rb(s);
}

static void	execute_both_down(t_cost *c, t_stacks *s)
{
	int	rrr_count;
	int	extra_a;
	int	extra_b;

	rrr_count = min_int(c->rra, c->rrb);
	extra_a = c->rra - rrr_count;
	extra_b = c->rrb - rrr_count;
	while (rrr_count--)
		op_rrr(s);
	while (extra_a--)
		op_rra(s);
	while (extra_b--)
		op_rrb(s);
}

static void	execute_a_up_b_down(t_cost *c, t_stacks *s)
{
	int	extra_a;
	int	extra_b;

	extra_a = c->ra;
	extra_b = c->rrb;
	while (extra_a--)
		op_ra(s);
	while (extra_b--)
		op_rrb(s);
}

static void	execute_a_down_b_up(t_cost *c, t_stacks *s)
{
	int	extra_a;
	int	extra_b;

	extra_a = c->rra;
	extra_b = c->rb;
	while (extra_a--)
		op_rra(s);
	while (extra_b--)
		op_rb(s);
}

void	execute_move(t_cost *c, t_stacks *s)
{
	if (c->scenario == BOTH_UP)
		execute_both_up(c, s);
	else if (c->scenario == BOTH_DOWN)
		execute_both_down(c, s);
	else if (c->scenario == A_UP_B_DOWN)
		execute_a_up_b_down(c, s);
	else
		execute_a_down_b_up(c, s);
	op_pb(s);
}
