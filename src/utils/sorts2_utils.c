/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:34:56 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/06/02 16:46:07 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_five(t_stacks *s)
{
	int	min_pos;
	int	size;

	size = stack_size(s->a);
	min_pos = find_position_of_min(s->a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			op_ra(s);
	else
		while (min_pos++ < size)
			op_rra(s);
	op_pb(s);
	size--;
	min_pos = find_position_of_min(s->a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			op_ra(s);
	else
		while (min_pos++ < size)
			op_rra(s);
	op_pb(s);
	sort_three(s);
	op_pa(s);
	op_pa(s);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	i = 0;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}
