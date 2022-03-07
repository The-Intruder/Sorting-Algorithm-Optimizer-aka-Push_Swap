/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static int	push_node(t_node *node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		stack->head->next = NULL;
		stack->head->prev = NULL;
		stack->size = 1;
	}
	else
	{
		node->next = stack->head;
		node->prev = NULL;
		stack->head->prev = node;
		stack->head = node;
		stack->size++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	push_stack(t_stack *stack_src, t_stack *stack_dst)
{
	t_node	*tmp_node;
	int		err;

	if (!stack_src || stack_src->size == 0 || !stack_src->head)
		return (-1);
	tmp_node = stack_src->head;
	if (stack_src->size > 1)
		stack_src->head = tmp_node->next;
	else
		reset_stack(stack_src, NULL);
	if (stack_src->size)
		stack_src->size--;
	patch_stack(stack_src);
	err = push_node(tmp_node, stack_dst);
	patch_stack(stack_dst);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	swap_stack(t_stack *stack)
{
	int	value;

	if (!stack || (!stack->head && !stack->tail) || stack->size < 2)
		return (-1);
	value = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = value;
	patch_stack(stack);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	rotate_stack(t_stack *stack)
{
	t_node	*tmp_node;

	if (!stack || !stack->head || stack->size < 2)
		return (-1);
	else if (stack->size == 2)
		swap_stack(stack);
	else
	{
		tmp_node = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->tail->next = tmp_node;
		tmp_node->prev = stack->tail;
		stack->tail = tmp_node;
		stack->tail->next = NULL;
	}
	patch_stack(stack);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	rev_rotate_stack(t_stack *stack)
{
	t_node	*tmp_node;

	if (!stack || !stack->head || stack->size < 2)
		return (-1);
	else if (stack->size == 2)
		swap_stack(stack);
	else
	{
		tmp_node = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		tmp_node->next = stack->head;
		tmp_node->prev = NULL;
		stack->head = tmp_node;
	}
	patch_stack(stack);
	return (0);
}

/* -------------------------------------------------------------------------- */
