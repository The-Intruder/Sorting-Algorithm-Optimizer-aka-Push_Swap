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
# include "libs/libft/libft.h"

/* -------------------------------- Typedef's ------------------------------- */
typedef struct s_stack_node {
	t_stack_node	*perv;
	unsigned int	indx;
	int				nmbr;
	t_stack_node	*next;
}	t_stack_node;

typedef struct s_stack_infos {
	t_stack			*head;
	t_stack			*tail;
	unsigned int	size;
}	t_stack_infos;

/* -------------------------------- Prototypes ------------------------------ */
void	check_errors(argc, argv);

int		swap_a(t_stack stack_a, t_stack stack_b);
int		swap_b(t_stack stack_a, t_stack stack_b);
int		swap_s(t_stack stack_a, t_stack stack_b);

int		push_a(t_stack stack_a, t_stack stack_b);
int		push_b(t_stack stack_a, t_stack stack_b);

int		rotate_a(t_stack stack_a, t_stack stack_b);
int		rotate_b(t_stack stack_a, t_stack stack_b);
int		rotate_r(t_stack stack_a, t_stack stack_b);

int		rev_rotate_a(t_stack stack_a, t_stack stack_b);
int		rev_rotate_b(t_stack stack_a, t_stack stack_b);
int		rev_rotate_r(t_stack stack_a, t_stack stack_b);

#endif
