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

// ~~~~ Sorting Operations' Masks ~~~~~~ //
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

/* -------------------------------- Typedef's ------------------------------- */
typedef unsigned int	t_uint;

typedef struct s_node {
	struct s_node	*prev;
	t_uint			indx;
	int				nmbr;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	t_uint	size;
}	t_stack;

// -------------//----------------- Prototypes ------------------------------ */
// init_stack.c //
//--------------//
int		init_stack(t_stack	*stack, int argc, char **argv);

//------------------//
// error_handling.c //
//------------------//
int		handle_err(int argc, char **argv);
void	p_err(char *err_msg);

//---------------//
// stack_ops_i.c //
//---------------//
int		push_stack(t_stack *stack_src, t_stack *stack_dst);
int		swap_stack(t_stack *stack);
int		rotate_stack(t_stack *stack);
int		rev_rotate_stack(t_stack *stack);

//----------------//
// stack_ops_ii.c //
//----------------//
int		check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b);

//--------------//
// misc_utils.c //
//--------------//
void	reset_stack(t_stack *stack_a, t_stack *stack_b);
void	patch_stack(t_stack *stack_a, t_stack *stack_b);

#endif
