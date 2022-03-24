/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static void	check_lis(t_node *node_i, t_node *node_j, int offset, \
	t_stack *stack_a)
{
	if (node_i->var_a < node_j->var_a + 1 || \
		(node_i->var_a == node_j->var_a + 1 && \
		node_j->value < node_i->prev_lis->value))
	{
		node_i->var_a = node_j->var_a + 1;
		node_i->var_b = offset;
		node_i->prev_lis = node_j;
		if ((t_uint)node_i->var_b >= stack_a->size)
			node_i->var_b -= stack_a->size;
	}
}

/* -------------------------------------------------------------------------- */
/*   node[0] == node_i     node[2] == node_j     node[2] == lis_prev_node     */

static void	lis_algo(t_stack *stack_a, t_node *lis_head, int offset)
{
	t_uint	i;
	t_uint	j;
	t_node	*node_i;
	t_node	*node_j;

	i = 1;
	lis_head->var_b = -1;
	node_i = lis_head->next;
	while (i < stack_a->size)
	{
		j = 0;
		node_j = lis_head;
		while (j < i)
		{
			if (node_j->value < node_i->value)
				check_lis(node_i, node_j, offset + j, stack_a);
			j++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
		i++;
	}
}

/* -------------------------------------------------------------------------- */

static void	reset_stack_vars(t_stack *stack, int mask)
{
	t_node	*node;
	t_uint	i;

	node = stack->head;
	i = 0;
	while (i++ < stack->size)
	{
		if (mask & VA)
			node->var_a = 0;
		if (mask & VB)
			node->var_b = 0;
		if (mask & VC)
			node->var_c = 1;
		node = node->next;
	}
}

/* -------------------------------------------------------------------------- */

static void	mark_lis_nodes(t_stack *stack_a)
{
	t_node	*lis_head;
	t_node	*node;
	int		i;

	lis_head = get_highst_lis_len_node(stack_a);
	node = lis_head;
	i = 0;
	while (i++ <= lis_head->var_a)
	{
		node->var_c = 0;
		node = node->prev_lis;
	}
}

/* -------------------------------------------------------------------------- */
/* var_a= lis_length |  var_b= lis_index |  var_c= max_lis_len_based_on_node  */

t_node	*apply_lis_algo(t_stack *stack_a)
{
	t_node		*node;
	t_uint		k;
	t_node		*lis_tail;

	k = 0;
	lis_tail = stack_a->head;
	while (k++ < stack_a->size)
	{
		lis_algo(stack_a, lis_tail, k);
		node = get_highst_lis_len_node(stack_a);
		lis_tail->var_c = node->var_a;
		reset_stack_vars(stack_a, (VA | VB));
		lis_tail = lis_tail->next;
	}
	lis_tail = get_highst_total_lis_len_node(stack_a);
	lis_algo(stack_a, lis_tail, get_head_distance(lis_tail, stack_a));
	reset_stack_vars(stack_a, (VB | VC));
	mark_lis_nodes(stack_a);
	return (lis_tail);
}

/* -------------------------------------------------------------------------- */