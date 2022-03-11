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
	node->var_c = 0;
	return (node);
}

/* -------------------------------------------------------------------------- */

static t_node	*get_highst_lislen_addr(t_stack *stack)
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

/* -- node[0] == node_i /|\ node[2] == node_j /|\ node[2] == lis_prev_node -- */

static void	lis_algo(t_stack *stack, t_uint i, t_node *lis_head, t_uint offset)
{
	t_uint	j;
	t_node	*node[3];

	node[0] = get_node_addr(lis_head, stack->size, i);
	j = 0;
	while (j < i)
	{
		node[1] = get_node_addr(lis_head, stack->size, j);
		if (node[1]->value < node[0]->value)
		{
			if (node[0]->var_b >= 0)
				node[2] = get_node_addr(stack->head, stack->size, \
					node[0]->var_b);
			if (node[0]->var_a < node[1]->var_a + 1 || \
				(node[0]->var_a == node[1]->var_a + 1 && \
				node[1]->value < node[2]->value))
			{
				node[0]->var_a = node[1]->var_a + 1;
				node[0]->var_b = j + offset;
				if ((t_uint)node[0]->var_b >= stack->size)
					node[0]->var_b -= stack->size;
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
	node = get_highst_lislen_addr(stack);
	while (node->var_b >= 0)
	{
		node->var_c = 0;
		node = get_node_addr(stack->head, stack->size, node->var_b);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */