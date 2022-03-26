/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* -------------------------------- Libraries ------------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/get_next_line/get_next_line.h"

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
/*  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  error_handling.c */
int			handle_err(int argc, char **new_argv);

/*  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -   init_stack.c */
int			init_stack(t_stack	*stack, int argc, char **argv);

/*  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - misc_utils_i.c */
void		reset_stack(t_stack *stack);
int			stack_is_sorted_from_node(t_node *node, t_uint stack_size);
void		patch_stack(t_stack *stack);
void		p_err(char *err_msg);
void		reset_stack_nodes_vars(t_stack *stack);

/*  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  misc_utils_iii.c */
void		free_exit(t_stack *stack_a, t_stack *stack_b);

/*  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  stack_ops_main.c */
int			check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b, \
	int print);

/*  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - stack_ops_utils.c */
int			push_stack(t_stack *stack_src, t_stack *stack_dst);
int			swap_stack(t_stack *stack);
int			rotate_stack(t_stack *stack);
int			rev_rotate_stack(t_stack *stack);

int			stack_is_sorted(t_stack *stack);

#endif