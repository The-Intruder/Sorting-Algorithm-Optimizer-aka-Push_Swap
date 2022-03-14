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

static int	get_node_index(t_node *node, t_stack *stack)
{
	t_uint	i;
	t_node	*tracer;

	i = 0;
	tracer = stack->head;
	while (i < stack->size)
	{
		if (node == tracer)
			return (i);
		tracer = tracer->next;
		i++;
	}
	return (-1);
}

/* -------------------------------------------------------------------------- */

static int	calcul_total_moves(int var_a, int var_b)
{
	if (are_same_sign(var_a, var_b))
	{
		if (abs(var_a) > abs(var_b))
			return (abs(var_a));
		else
			return (abs(var_b));
	}
	else
		return (abs(var_a) + abs(var_b));
}

/* -------------------------------------------------------------------------- */

static int	count_head_distance(int index, t_stack *stack)
{
	if ((t_uint)index > (stack->size / 2))
		return ((stack->size - index) * -1);
	else
		return (index);
}

/* -------------------------------------------------------------------------- */

static int	calcul_number_diff(int nb1, int nb2)
{
	if (are_same_sign(nb1, nb2))
	{
		if (abs(nb1) > abs(nb2))
			return (abs(nb1));
		else
			return (abs(var_b));
	}
	return (abs(nb1) + abs(nb2));
}

/* -------------------------------------------------------------------------- */

static void	update_stacka_number_diff(t_stack *stack_a, int ref_value)
{
	t_node	*node;
	t_uint	i;

	i = 0;
	node = stack_a->head;
	while (i++ < stack_a->size)
	{
		node->var_c = -1;
		if (node->value > ref_value)
			node->var_c = calcul_number_diff(node->value, ref_value);
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
	node = stack_a->head;
	tracer = stack_a->head->next;
	i = 0;
	while (i < stack_a->size)
	{
		if (tracer->var_c >= 0 && tracer->var_c < node->var_c)
			node = tracer;
		tracer = tracer->next;
		i++;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	get_best_moves_head_a(t_stack *stack_a, int value)
{
	t_node	*lowst_varc_node;
	int		index;
	int		moves;

	update_stacka_number_diff(stack_a, value);
	lowst_varc_node = get_lowest_var_c_node(stack_a);
	index = get_node_index(lowst_varc_node, stack_a);
	moves = count_head_distance(index, stack_a);
	
	return (moves);
}

/* -------------------------------------------------------------------------- */

static void update_sorting_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_uint	i;
	t_node	*node;

	if (!stack_a || !stack_b)
		return (exit(-1));
	i = 0;
	node = stack_b->head;
	while (i < stack_b->size)
	{
		node->var_a = get_best_moves_head_a(stack_a, node->value);
		node->var_b = count_head_distance(i, stack_b);
		node->var_c = calcul_total_moves(node->var_a, node->var_b);
		node = node->next;
		++i;
	}
	//reset_stack_nodes_vars(stack_a);
}

/* -------------------------------------------------------------------------- */

// static void	push_lowest_to_head(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*node;
// 	int		index;
// 	int		op;

// 	node = get_lowst_val_addr(stack_a);
// 	index = get_node_index(node, stack_a);
// 	if ((t_uint)index > (stack_a->size / 2))
// 		op = RRA;
// 	else
// 		op = RA;
// 	while (stack_a->head != node)
// 		check_exec_op(op, stack_a, stack_b);
// }

/* -------------------------------------------------------------------------- */

void	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int i;

	i = 0;
	while (i++ < 1)
	{
		update_sorting_moves(stack_a, stack_b);
		node = get_lowest_var_c_node(stack_b);
		//exec_condit_push(node, stack_a, stack_b);
	}
	//push_lowest_to_head(stack_a, stack_b);
}

/* -------------------------------------------------------------------------- */
