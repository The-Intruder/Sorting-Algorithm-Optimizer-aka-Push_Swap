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

t_node	*get_smallest_value_node(t_stack *stack)
{
	t_node	*tracer;
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->head;
	tracer = NULL;
	if (stack->head->next)
		tracer = stack->head->next;
	while (tracer)
	{
		if (tracer->value < node->value)
			node = tracer;
		tracer = tracer->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

static t_node	*get_node_addr(t_stack *ostack, t_stack *fstack, t_uint index)
{
	t_uint	i;
	t_node	*node;

	if (!fstack || !fstack->size || !fstack->head || index >= fstack->size)
		return (NULL);
	i = 0;
	node = fstack->head;
	while (i < index && i++ < ostack->size)
	{
		node = node->next;
		if (!node)
			node = ostack->head;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

static int	apply_lis_algo_ii(t_stack *stack, t_node *node_i, int i, int j)
{
	t_node	*node_j;
	t_node	*prev_sorted_node;

	while (j < i)
	{
		node_j = get_node_addr(stack, j);
		if (node_j->value < node_i->value)
		{
			prev_sorted_node = get_node_addr(stack, node_i->prev_indx);
			if (node_i->subseq_len < node_j->subseq_len + 1 || \
				(node_i->subseq_len == node_j->subseq_len + 1 && \
				node_j->value < prev_sorted_node->value))
			{
				node_i->subseq_len = node_j->subseq_len + 1;
				node_i->prev_indx = j;
			}
		}
		j++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	apply_lis_algo(t_stack *stack)
{
	t_node	*node_i;
	t_stack	fake_stack;
	t_uint	i;
	t_uint	j;

	i = 1;
	fake_stack.head = get_smallest_value_node(stack);
	fake_stack.tail = fake_stack.head->prev;
	fake_stack.size = stack->size;
	while (i < stack->size)
	{
		node_i = get_node_addr(stack, &fake_stack, i);
		j = 0;
		apply_lis_algo_ii(stack, node_i, i, j);
		i++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */