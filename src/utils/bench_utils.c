/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:57:23 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/30 20:55:34 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bench_init(t_bench *b, t_strategy mode, int enabled)
{
	ft_bzero(b, sizeof(t_bench));
	b->mode = mode;
	b->executed = mode;
	b->enabled = (enabled == 1);
}

t_strategy	get_strategy_from_flag(const char *flag)
{
	if (ft_strncmp(flag, "--simple", sizeof("--simple")) == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strncmp(flag, "--medium", sizeof("--medium")) == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strncmp(flag, "--complex", sizeof("--complex")) == 0)
		return (STRATEGY_COMPLEX);
	return (STRATEGY_ADAPTIVE);
}

const char	*get_strategy_name(t_strategy s)
{
	if (s == STRATEGY_SIMPLE)
		return ("Simple");
	if (s == STRATEGY_MEDIUM)
		return ("Medium");
	if (s == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

const char	*get_strategy_complexity(t_strategy s)
{
	if (s == STRATEGY_SIMPLE)
		return ("O(n²)");
	if (s == STRATEGY_MEDIUM)
		return ("O(n√n)");
	if (s == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("");
}

int	bench_total(t_bench *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb
		+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr);
}
