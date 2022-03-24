/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static void	update_stacka_number_diff(t_stack *stack_a, t_uint index)
{
	t_node	*node;
	t_uint	i;

	i = 0;
	node = stack_a->head;
	while (i++ < stack_a->size)
	{
		if (node->index > index)
			node->var_c = node->index - index;
		else if (node->index < index)
			node->var_c = index - node->index;
		else
			node->var_c = stack_a->size;
		node = node->next;
	}
}

/* -------------------------------------------------------------------------- */

static t_node	*get_lowest_var_c_node(t_stack *stack_a)
{
	t_uint	i;
	t_node	*node;
	t_node	*tracer;

	if (!stack_a || stack_a->size == 0)
		return (NULL);
	node = NULL;
	tracer = stack_a->head;
	i = 0;
	while (i < stack_a->size)
	{
		if (!node && tracer->var_c >= 0)
			node = tracer;
		else if (tracer->var_c >= 0 && tracer->var_c < node->var_c)
			node = tracer;
		tracer = tracer->next;
		i++;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	get_best_moves_head_a(t_stack *stack_a, t_uint sort_index)
{
	t_node	*lowst_varc_node;
	t_uint	index;
	int		moves;

	update_stacka_number_diff(stack_a, sort_index);
	lowst_varc_node = get_lowest_var_c_node(stack_a);
	if (lowst_varc_node && lowst_varc_node->index < sort_index)
		lowst_varc_node = lowst_varc_node->next;
	index = get_node_index(lowst_varc_node, stack_a);
	moves = count_head_distance(index, stack_a);
	return (moves);
}

/* -------------------------------------------------------------------------- */

static void	update_sorting_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_uint	i;
	t_node	*node;

	if (!stack_a || !stack_b)
		return (exit(-1));
	i = 0;
	node = stack_b->head;
	while (i < stack_b->size)
	{
		node->var_a = get_best_moves_head_a(stack_a, node->index);
		node->var_b = count_head_distance(i, stack_b);
		if (!are_same_sign(node->var_a, node->var_b))
			calcul_optimized_moves(node, stack_a, stack_b);
		node->var_c = calcul_total_moves(node->var_a, node->var_b);
		node = node->next;
		++i;
	}
	reset_stack_nodes_vars(stack_a);
}

/* -------------------------------------------------------------------------- */

void	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;

	i = 0;
	while (stack_b->size)
	{
		update_sorting_moves(stack_a, stack_b);
		node = get_lowest_var_c_node(stack_b);
		exec_condit_push(node, stack_a, stack_b);
	}
	push_lowest_to_head(stack_a, stack_b);
}

/* -------------------------------------------------------------------------- */
