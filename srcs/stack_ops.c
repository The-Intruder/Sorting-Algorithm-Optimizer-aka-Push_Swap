/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static int	swap_stack(t_stack *stack)
{
	t_node	*tmp_node;

	if (!stack || (!stack->head && !stack->tail) || stack->size < 2)
		return (-1);
	tmp_node = stack->head;
	stack->head = stack->head->next;
	tmp_node->next = stack->head->next;
	tmp_node->next->prev = tmp_node;
	tmp_node->prev = stack->head;
	stack->head->next = tmp_node;
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	push_stack(t_stack *stack_src, t_stack *stack_dst)
{
	t_node	*tmp_node;

	if (!stack_src || stack_src->size == 0 || !stack_src->head)
		return (-1);
	tmp_node = stack_src->head;
	stack_src->head = stack_src->head->next;
	stack_src->head->prev = stack_src->tail;
	stack_src->tail->next = stack_src->head;
	stack_src->size -= 1;
	if (stack_dst->size)
	{
		stack_dst->head->prev = tmp_node;
		stack_dst->tail->next = tmp_node;
		tmp_node->prev = stack_dst->tail;
		tmp_node->next = stack_dst->head;
		stack_dst->head = tmp_node;
		stack_dst += 1;
	}
	else
	{
		stack_dst->head = tmp_node;
		stack_dst->head->next = NULL;
		stack_dst->head->prev = NULL;
		stack_dst->size = 1;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

// static int	rotate_stack(t_stack *stack)
// {
// 	return (0);
// }

/* -------------------------------------------------------------------------- */

// static int	rev_rotate_stack(t_stack *stack)
// {
// 	return (0);
// }

/* -------------------------------------------------------------------------- */

int	check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b)
{
	int	err;

	err = 0;
	if (op_mask & (SA | SB))
	{
		err = swap_stack(stack_a);
		err = swap_stack(stack_b);
	}
	else if (op_mask & PA)
		err = push_stack(stack_b, stack_a);
	else if (op_mask & PB)
		err = push_stack(stack_a, stack_b);
	// else if (op_mask & (RA | RB))
	// {
	// 	err = rotate_stack(stack_a);
	// 	err = rotate_stack(stack_b);
	// }
	// else if (op_mask & ( RRA | RRB))
	// {
	// 	err = rev_rotate_stack(stack_a);
	// 	err = rev_rotate_stack(stack_b);
	// }
	return (err);
}

/* -------------------------------------------------------------------------- */
