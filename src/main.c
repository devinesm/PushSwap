/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/31 14:58:07 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	error_exit(t_stacks *s)
{
	if (s)
	{
		free_stack(&s->a);
		free_stack(&s->b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

static int	get_list_start(int argc, char **argv, char **strategy, int *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--simple", sizeof("--simple"))
			|| !ft_strncmp(argv[i], "--medium", sizeof("--medium"))
			|| !ft_strncmp(argv[i], "--complex", sizeof("--complex"))
			|| !ft_strncmp(argv[i], "--adaptive", sizeof("--adaptive")))
			*strategy = argv[i];
		else if (!ft_strncmp(argv[i], "--bench", sizeof("--bench")))
			*bench = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		*strategy;
	int			bench_mode;
	int			i;

	if (argc < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	strategy = "--adaptive";
	bench_mode = 0;
	i = get_list_start(argc, argv, &strategy, &bench_mode);
	if (argc == i)
		return (0);
	bench_init(&s.benchmarks, get_strategy_from_flag(strategy), bench_mode);
	s.a = parse_args(argc - i, argv + i);
	if (!s.a)
		error_exit(&s);
	if (!is_sorted(s.a))
		sort(&s, strategy);
	if (bench_mode)
		print_bench(&s.benchmarks);
	free_stack(&(s.a));
	return (0);
}
