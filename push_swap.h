/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/06/02 16:44:40 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_dprintf/ft_dprintf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}					t_strategy;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				pa;
	int				pb;
	int				rra;
	int				rrb;
	int				rrr;
	t_strategy		mode;
	t_strategy		executed;
	double			disorder;
	int				enabled;

}					t_bench;

typedef struct s_stacks
{
	t_node			*a;
	t_node			*b;
	t_bench			benchmarks;
}					t_stacks;

typedef enum e_scenario
{
	BOTH_UP,
	BOTH_DOWN,
	A_UP_B_DOWN,
	A_DOWN_B_UP
}					t_scenario;

typedef struct s_cost
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				total;
	t_scenario		scenario;
}					t_cost;

/* operations */
void				op_sa(t_stacks *s);
void				op_sb(t_stacks *s);
void				op_ss(t_stacks *s);
void				op_pa(t_stacks *s);
void				op_pb(t_stacks *s);
void				op_ra(t_stacks *s);
void				op_rb(t_stacks *s);
void				op_rr(t_stacks *s);
void				op_rra(t_stacks *s);
void				op_rrb(t_stacks *s);
void				op_rrr(t_stacks *s);

/* sort */
double				compute_disorder(t_node *stack);
void				sort_complex(t_stacks *s);
void				sort_medium(t_stacks *s);
void				sort_simple(t_stacks *s);
void				sort_turk(t_stacks *s);
void				sort(t_stacks *s, char *strategy);

/* utils */
/* args */
int					has_duplicate(t_node *stack, int nb);
int					append_node(t_node **stack, int value);

/* bench */
void				bench_init(t_bench *b, t_strategy mode, int enabled);
t_strategy			get_strategy_from_flag(const char *flag);
const char			*get_strategy_name(t_strategy s);
const char			*get_strategy_complexity(t_strategy s);
void				print_bench(t_bench *b);

/* stacks */
void				free_stack(t_node **stack);
int					is_sorted(t_node *stack);
int					stack_size(t_node *stack);
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);

/* sorts */
int					ft_sqrt(int number);
void				assign_index(t_stacks *s);
void				sort_three(t_stacks *s);
int					find_position_of_min(t_node *a);
int					max_int(int a, int b);
int					min_int(int a, int b);

/* turk sort */
void				execute_move(t_cost *c, t_stacks *s);
int					target_position_in_b(int x, t_node *b);
void				push_b_to_a(t_stacks *s);
void				rotate_min_to_top(t_stacks *s);

/* parse args */
t_node				*parse_args(int argc, char **argv);

/* bench print helpers */
void				print_disorder(t_bench *b);
void				print_strategy(t_bench *b);
void				print_total(t_bench *b);
void				print_ops_line1(t_bench *b);
void				print_ops_line2(t_bench *b);
void				print_bench(t_bench *b);

/* main */
int					main(int argc, char **argv);

#endif
