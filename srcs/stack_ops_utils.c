/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static void	push_node(t_node *node, t_stack *stack)
{
	if (stack->size > 0)
	{
		node->next = stack->head;
		node->prev = stack->tail;
		stack->head->prev = node;
		stack->tail->next = node;
	}
	else
	{
		stack->tail = node;
		stack->tail->next = NULL;
		stack->tail->prev = NULL;
	}
	stack->head = node;
	stack->size++;
	patch_stack(stack);
}

/* -------------------------------------------------------------------------- */

int	push_stack(t_stack *stack_src, t_stack *stack_dst)
{
	t_node	*tmp_node;

	if (!stack_src || stack_src->size == 0 || !stack_src->head)
		return (-1);
	tmp_node = stack_src->head;
	if (stack_src->size >= 1)
	{
		stack_src->head = stack_src->head->next;
		stack_src->tail->next = stack_src->head;
		stack_src->head->prev = stack_src->tail;
		stack_src->size--;
	}
	else
		reset_stack(stack_src);
	push_node(tmp_node, stack_dst);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	swap_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head || !stack->tail || stack->size < 2)
		return (-1);
	node = stack->head;
	stack->head = stack->head->next;
	node->next = stack->head->next;
	node->next->prev = node;
	stack->head->next = node;
	node->prev = stack->head;
	stack->head->prev = stack->tail;
	patch_stack(stack);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	rotate_stack(t_stack *stack)
{
	if (!stack || !stack->head || !stack->tail || stack->size < 2)
		return (-1);
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	patch_stack(stack);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	rev_rotate_stack(t_stack *stack)
{
	if (!stack || !stack->head || stack->size < 2)
		return (-1);
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	patch_stack(stack);
	return (0);
}

/* -------------------------------------------------------------------------- */
