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

// init_stack.c

//  lis_algo.c

//  lis_filtering.c

//  lis_misc.c

//  misc_utils_i.c

//  misc_utils_ii.c


//  sorting_algo_i.c

//  sorting_algo_ii.c

//  sorting_algo_iii.c

//  stack_ops_main.c

//  stack_ops_utils.c


#endif