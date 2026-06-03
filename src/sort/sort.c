/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/06/03 21:11:25 by fiolivei          #+#    #+#             */
/*   Updated: 2026/06/03 21:11:25 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	execute_strategy(t_stacks *s, int strategy_type)
{
	s->benchmarks.executed = strategy_type;
	if (strategy_type == STRATEGY_SIMPLE)
		sort_simple(s);
	else if (strategy_type == STRATEGY_MEDIUM)
		sort_medium(s);
	else
		sort_turk(s);
}

void	sort(t_stacks *s, char *strategy)
{
	double	disorder;

	disorder = compute_disorder(s->a);
	s->benchmarks.disorder = disorder;
	if (!ft_strncmp(strategy, "--simple", sizeof("--simple")))
		execute_strategy(s, STRATEGY_SIMPLE);
	else if (!ft_strncmp(strategy, "--medium", sizeof("--medium")))
		execute_strategy(s, STRATEGY_MEDIUM);
	else if (!ft_strncmp(strategy, "--complex", sizeof("--complex")))
		execute_strategy(s, STRATEGY_COMPLEX);
	else if (!ft_strncmp(strategy, "--adaptive", sizeof("--adaptive")))
	{
		if (disorder < 0.2)
			execute_strategy(s, STRATEGY_SIMPLE);
		else if (disorder < 0.5)
			execute_strategy(s, STRATEGY_MEDIUM);
		else
			execute_strategy(s, STRATEGY_COMPLEX);
	}
}
