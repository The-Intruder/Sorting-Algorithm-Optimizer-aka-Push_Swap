/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

t_node	*get_lowest_value_node(t_stack *stack)
{
	t_node	*tracer;
	t_node	*node;
	t_uint	i;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->head;
	tracer = NULL;
	if (stack->head->next != stack->head)
		tracer = stack->head->next;
	else
		return (node);
	i = 0;
	while (i++ < stack->size)
	{
		if (tracer->value < node->value)
			node = tracer;
		tracer = tracer->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

t_node	*get_highst_lis_len_node(t_stack *stack)
{
	t_node	*tracer;
	t_node	*node;
	t_uint	i;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->head;
	tracer = NULL;
	if (stack->head->next)
		tracer = stack->head->next;
	i = 0;
	while (i++ < stack->size)
	{
		if (tracer->var_a > node->var_a)
			node = tracer;
		tracer = tracer->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

t_node	*get_highst_total_lis_len_node(t_stack *stack)
{
	t_node	*tracer;
	t_node	*node;
	t_uint	i;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->head;
	tracer = NULL;
	if (stack->head->next)
		tracer = stack->head->next;
	i = 0;
	while (i++ < stack->size)
	{
		if (tracer->var_c > node->var_c)
			node = tracer;
		else if (tracer->var_c == node->var_c && tracer->value < node->value)
			node = tracer;
		tracer = tracer->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

t_node	*get_node_addr(t_node *start_node, t_uint stack_size, t_uint index)
{
	t_uint	i;
	t_node	*node;

	if (!start_node || !stack_size || index >= stack_size)
		return (NULL);
	i = 0;
	node = start_node;
	while (i < index && i++ < stack_size)
		node = node->next;
	return (node);
}

/* -------------------------------------------------------------------------- */

t_uint	get_head_distance(t_node *lis_head, t_stack *stack)
{
	t_node	*node;
	t_uint	offset;

	node = stack->head;
	offset = 0;
	while (node != lis_head)
	{
		node = node->next;
		offset++;
	}
	return (offset);
}

/* -------------------------------------------------------------------------- */
