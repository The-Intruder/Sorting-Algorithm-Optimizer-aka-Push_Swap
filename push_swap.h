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

/* 
Notes:
LIS Algo
var_a: lis_length
var_b: lis_index
var_c: lis_boolean

Sorting Algo
var_a: moves_to_head_count
var_b: 
var_c: 

*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* -------------------------------- Libraries ------------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
// # include <stdio.h>
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

// ~~~~ Sorting Operations' Masks ~~~~~~ //
# define SA		0b0000000000001
# define SB		0b0000000000010
# define SS		0b0000000000100
# define PA		0b0000000001000
# define PB		0b0000000010000
# define RA		0b0000000100000
# define RB		0b0000001000000
# define RR		0b0000010000000
# define RRA	0b0000100000000
# define RRB	0b0001000000000
# define RRR	0b0010000000000
# define UH		0b0100000000000
# define LH		0b1000000000000

/* -------------------------------- Typedef's ------------------------------- */
typedef unsigned int	t_uint;

typedef struct s_node {
	struct s_node	*prev;
	int				value;
	int				var_a;
	int				var_b;
	int				var_c;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	t_uint	size;
}	t_stack;

// -------------------------------- Prototypes ------------------------------ */
// init_stack.c			//
int		init_stack(t_stack	*stack, int argc, char **argv);

// error_handling.c		//
int		handle_err(int argc, char **argv);

//  stack_ops_utils.c	//
int		push_stack(t_stack *stack_src, t_stack *stack_dst);
int		swap_stack(t_stack *stack);
int		rotate_stack(t_stack *stack);
int		rev_rotate_stack(t_stack *stack);

//  stack_ops_main.c	//
int		check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b);

//  misc_utils.c		//
void	reset_stack(t_stack *stack);
void	patch_stack(t_stack *stack);
void	p_err(char *err_msg);

//  long_incr_sub.c		//
t_node	*get_node_addr(t_node *start_node, t_uint stack_size, t_uint index);
t_node	*get_lowst_val_addr(t_stack *stack);
int		apply_lis_algo(t_stack *stack);

//  testing_functions.c	//
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	exec_print_op(int op_mask, t_stack *stack_a, t_stack *stack_b, int op);

//  sorting_algo_i.c	//
//int	update_best_moves_to_head(t_stack *stack);
// int		calculate_total_sorting_moves(t_stack *stack_a, t_stack *stack_b);
// int		count_moves_to_head(t_uint index, t_stack *stack);
int		push_non_lis_node_to_stackb(t_stack *stack_a, t_stack *stack_b);
// int	sort_numbers(t_stack *stack_a, t_stack *stack_b);

#endif
