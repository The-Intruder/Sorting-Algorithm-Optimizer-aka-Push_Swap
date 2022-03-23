/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* -------------------------------- Libraries ------------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

/* ---------------------------------- Macros -------------------------------- */
// ~~~~ Terminal Color Codes ~~~~~~ //
# define NC		"\033[31;0m"				// Len: 7
# define BLD	"\033[31;0m\033[1m"			// Len: 11
# define RED	"\033[31;0m\033[0;31;1m"	// Len: 16
# define YEL	"\033[31;0m\033[0;33;1m"	// Len: 16
# define GRA	"\033[31;0m\033[0;37;1m"	// Len: 16
# define CYN	"\033[31;0m\033[0;36;1m"	// Len: 16
# define GRN	"\033[31;0m\033[0;32;1m"	// Len: 16
# define MGN	"\033[31;0m\033[0;35;1m"	// Len: 16
# define BLU	"\033[31;0m\033[0;34;1m"	// Len: 16

// ~~~~~~~~~~~~ Masks ~~~~~~~~~~~~ //
# define SA		0b00000000001
# define SB		0b00000000010
# define SS		0b00000000100
# define PA		0b00000001000
# define PB		0b00000010000
# define RA		0b00000100000
# define RB		0b00001000000
# define RR		0b00010000000
# define RRA	0b00100000000
# define RRB	0b01000000000
# define RRR	0b10000000000

# define VA		0b00100000000000
# define VB		0b01000000000000
# define VC		0b10000000000000

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

/* -------------------------------- Typedef's ------------------------------- */
typedef unsigned int	t_uint;

typedef struct s_node {
	struct s_node	*prev;
	int				value;
	long long		var_a;
	long long		var_b;
	long long		var_c;
	long			index;
	struct s_node	*prev_lis;
	struct s_node	*next_lis;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	t_uint	size;
}	t_stack;

// -------------------------------- Prototypes ------------------------------ */
// error_handling.c
int		handle_err(int argc, char **new_argv);
int		is_all_valid_digits(char **argv);

// init_stack.c
int		init_stack(t_stack	*stack, int argc, char **argv);
int		stack_is_sorted_from_node(t_node *node, t_uint stack_size);

//  lis_algo.c
void	lis_algo(t_stack *stack_a, t_node *lis_head, int offset);

//  lis_filtering.c


//  lis_misc.c
t_node	*get_lowest_value_node(t_stack *stack);
t_node	*get_highst_lis_len_node(t_stack *stack);
t_node	*get_highst_total_lis_len_node(t_stack *stack);
t_node	*get_node_addr(t_node *start_node, t_uint stack_size, t_uint index);
t_uint	get_head_distance(t_node *lis_head, t_stack *stack);

//  misc_utils_i.c
void	reset_stack(t_stack *stack);
void	reset_stack_nodes_vars(t_stack *stack);
void	patch_stack(t_stack *stack);
void	p_err(char *err_msg);
int		is_positive(int nbr);
int		are_same_sign(int nbr1, int nbr2);
int		stack_is_sorted(t_stack *stack);
//  misc_utils_ii.c


//  sorting_algo_i.c
void	sort_numbers(t_stack *stack_a, t_stack *stack_b);
//  sorting_algo_ii.c
void	calcul_optimized_moves(t_node *node, t_stack *stack_a, t_stack *stack_b);
void	push_lowest_to_head(t_stack *stack_a, t_stack *stack_b);
void	exec_condit_push(t_node *node, t_stack *stack_a, t_stack *stack_b);
//  sorting_algo_iii.c
long long	calcul_number_diff(int nb1, int nb2);
int			calcul_total_moves(int var_a, int var_b);
int			get_index_from_head_moves(int moves, int stack_size);
int			get_node_index(t_node *node, t_stack *stack);
int			count_head_distance(int index, t_stack *stack);

//  stack_ops_main.c
int		check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b);
//  stack_ops_utils.c
int		push_stack(t_stack *stack_src, t_stack *stack_dst);
int		swap_stack(t_stack *stack);
int		rotate_stack(t_stack *stack);
int		rev_rotate_stack(t_stack *stack);

long long	my_abs(int nbr);
t_node		*get_lowst_val_addr(t_stack *stack);
t_node		*apply_lis_algo(t_stack *stack_a);
void		mark_lis_nodes(t_stack *stack_a);

void	reset_stack_vars(t_stack *stack, int mask);
int		swap_to_sort(t_stack *stack_a, t_stack *stack_b, t_node *lis_tail);
int		push_non_lis_node_to_stackb(t_stack *stack_a, t_stack *stack_b);

/* ========================================================================== */
//  testing_functions.c
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	print_stack_min(t_stack *stack_a);
/* ========================================================================== */

// Notes:
// LIS Algo
// var_a: lis_length
// var_b: lis_index
// var_c: lis_boolean

// Sorting Algo
// var_a: moves_to_head_count: stack_a
// var_b: moves_to_head_count: stack_b
// var_c: var_a + var_b

#endif
