/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

void	reset_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->size = 0;
	stack->tail = NULL;
}

/* -------------------------------------------------------------------------- */

void	patch_stack(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return ;
	if (stack->head && stack->tail)
	{
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
	}
}

/* -------------------------------------------------------------------------- */

void	p_err(char *err_msg)
{
	write(2, RED"\nERROR:\t"BLD, 36);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, NC"\n\n", 9);
}

/* -------------------------------------------------------------------------- */

void	reset_stack_nodes_vars(t_stack *stack)
{
	t_uint	i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i++ < stack->size)
	{
		node->var_a = 0;
		node->var_b = 0;
		node->var_c = 0;
		node = node->next;
	}
}

/* -------------------------------------------------------------------------- */
