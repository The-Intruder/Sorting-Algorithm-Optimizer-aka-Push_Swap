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
# include <stdio.h>
//# include "libs/libft/libft.h"
//# include "libs/ft_printf/ft_printf.h"

/* ---------------------------------- Macros -------------------------------- */
# define BLD "\033[31;0m\033[1m"
# define NC "\033[31;0m"
# define RED "\033[31;0m\033[0;31;1m"
# define YEL "\033[31;0m\033[0;33;1m"
# define GRA "\033[31;0m\033[0;37;1m"
# define CYN "\033[31;0m\033[0;36;1m"
# define GRN "\033[31;0m\033[0;32;1m"
# define MGN "\033[31;0m\033[0;35;1m"
# define BLU "\033[31;0m\033[0;34;1m"

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

/* -------------------------------- Prototypes ------------------------------ */
t_stack	*init_stack(int argc, char **argv);

int		swap_stack(t_stack *stack);
int		push_stack(t_stack *stack_src, t_stack *stack_dst);
int		rotate_stack(t_stack *stack);
int		rev_rotate_stack(t_stack *stack);

#endif
