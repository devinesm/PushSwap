/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:06:52 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/05/31 16:06:52 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	has_duplicate(t_node *stack, int nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	append_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	new_node->index = 0;
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	return (1);
}
