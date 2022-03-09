/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_incr_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

t_node	*get_lowst_val_addr(t_stack *stack)
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
		if (tracer->value < node->value)
			node = tracer;
		tracer = tracer->next;
	}
	node->lis_bool = true;
	return (node);
}

/* -------------------------------------------------------------------------- */

static t_node	*get_highst_lis_len_addr(t_stack *stack)
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
		if (tracer->lis_len > node->lis_len)
			node = tracer;
		tracer = tracer->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

static t_node	*get_node_addr(t_node *start_node, t_uint stack_size, \
	t_uint index)
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

static void	lis_algo(t_stack *stack, t_uint i, t_node *lis_head, t_uint offset)
{
	t_node	*i_node;
	t_uint	j;
	t_node	*j_node;
	t_node	*lis_prev_node;

	i_node = get_node_addr(lis_head, stack->size, i);
	j = 0;
	while (j < i)
	{
		j_node = get_node_addr(lis_head, stack->size, j);
		if (j_node->value < i_node->value)
		{
			if (i_node->lis_indx >= 0)
				lis_prev_node = get_node_addr(stack->head, stack->size, i_node->lis_indx);
			if (i_node->lis_len < j_node->lis_len + 1 || \
				(i_node->lis_len == j_node->lis_len + 1 && \
				j_node->value < lis_prev_node->value))
			{
				i_node->lis_len = j_node->lis_len + 1;
				i_node->lis_indx = j + offset;
				if ((t_uint)i_node->lis_indx >= stack->size)
					i_node->lis_indx -= stack->size;
			}
		}
		j++;
	}
}

/* -------------------------------------------------------------------------- */

int	apply_lis_algo(t_stack *stack)
{
	t_node	*node;
	t_uint	i;
	t_node	*lis_head;
	t_uint	offset;

	i = 1;
	lis_head = get_lowst_val_addr(stack);
	offset = 0;
	node = stack->head;
	while (node != lis_head)
	{
		node = node->next;
		offset++;
	}
	while (i < stack->size)
		lis_algo(stack, i++, lis_head, offset);
	node = get_highst_lis_len_addr(stack);
	while (node->lis_indx >= 0)
	{
		node->lis_bool = true;
		node = get_node_addr(stack->head, stack->size, node->lis_indx);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */