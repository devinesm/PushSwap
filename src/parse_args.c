/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/30 20:36:17 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

static void	free_split(char **split_arr)
{
	int	i;

	i = 0;
	if (!split_arr)
		return ;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

static int	process_split(char **split_arr, t_node **stack_a)
{
	int		j;
	long	nb;

	j = 0;
	while (split_arr[j])
	{
		if (!is_valid_format(split_arr[j]))
			return (0);
		nb = ft_atol(split_arr[j]);
		if (nb < INT_MIN || nb > INT_MAX || has_duplicate(*stack_a, (int)nb))
			return (0);
		if (!append_node(stack_a, (int)nb))
			return (0);
		j++;
	}
	return (1);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack_a;
	char	**split_arr;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < argc)
	{
		split_arr = ft_split(argv[i], ' ');
		if (!split_arr || !split_arr[0] || !process_split(split_arr, &stack_a))
		{
			free_split(split_arr);
			free_stack(&stack_a);
			return (NULL);
		}
		free_split(split_arr);
		i++;
	}
	return (stack_a);
}
