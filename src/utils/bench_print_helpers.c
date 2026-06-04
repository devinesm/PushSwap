/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 20:58:48 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/31 19:16:23 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_disorder(t_bench *b)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(b->disorder * 100);
	dec_part = (int)(b->disorder * 10000) % 100;
	if (dec_part < 10)
		ft_dprintf(2, "[bench] disorder: %d.0%d%%\n", int_part, dec_part);
	else
		ft_dprintf(2, "[bench] disorder: %d.%d%%\n", int_part, dec_part);
}

void	print_strategy(t_bench *b)
{
	ft_dprintf(2, "[bench] strategy: %s / %s\n", get_strategy_name(b->mode),
		get_strategy_complexity(b->executed));
}

void	print_total(t_bench *b)
{
	ft_dprintf(2, "[bench] total ops: %d\n", bench_total(b));
}

void	print_ops_line1(t_bench *b)
{
	ft_dprintf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n", b->sa,
		b->sb, b->ss, b->pa, b->pb);
}

void	print_ops_line2(t_bench *b)
{
	ft_dprintf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}
