/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:59:47 by fiolivei          #+#    #+#             */
/*   Updated: 2026/06/03 22:00:41 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_bench(t_bench *b)
{
	if (!b->enabled)
		return ;
	print_disorder(b);
	print_strategy(b);
	print_total(b);
	print_ops_line1(b);
	print_ops_line2(b);
}
