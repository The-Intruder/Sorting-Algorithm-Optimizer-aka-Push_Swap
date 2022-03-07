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

int	put_true_index(t_stack *stack)
{
	int	i;
	
}

/* -------------------------------------------------------------------------- */

static t_node	*get_node_addr(t_stack *stack, t_uint index)
{
	t_uint	i;
	t_node	*node;

	if (!stack || !stack->size || !stack->head || index >= stack->size)
		return (NULL);
	i = 0;
	node = stack->head;
	while (i++ < index && node)
		node = node->next;
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	get_node_value(t_stack *stack, t_uint index)
{
	t_uint	i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i++ < index && node->next)
		node = node->next;
	return (node->value);
}

/* -------------------------------------------------------------------------- */

static int	apply_lis_algo_ii(t_stack *stack, t_node *node_i, int i, int j)
{
	t_node *node_j;

	while (j < i)
	{
		node_j = get_node_addr(stack, j);
		if (node_j->value < node_i->value)
		{
			if (node_i->subseq_len < node_j->subseq_len + 1 || \
			(node_i->subseq_len == node_j->subseq_len + 1 && \
			node_j->value < get_node_value(stack, node_i->prev_indx)))
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
	t_uint	i;
	t_uint	j;

	i = 1;
	while (i < stack->size)
	{
		node_i = get_node_addr(stack, i);
		j = 0;
		apply_lis_algo_ii(stack, node_i, i, j);
		i++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */