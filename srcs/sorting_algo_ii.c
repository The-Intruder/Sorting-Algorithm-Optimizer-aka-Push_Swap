/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_ii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

void	calcul_optimized_moves(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	var_a_index;
	int	var_b_index;

	var_a_index = get_index_from_head_moves(node->var_a, stack_a->size);
	var_b_index = get_index_from_head_moves(node->var_b, stack_b->size);
	if (var_a_index > (int)stack_a->size / 2 && var_a_index > var_b_index)
	{
		if (calcul_total_moves(var_a_index, var_b_index) < calcul_total_moves(node->var_a, node->var_b))
			node->var_a = var_a_index;
	}
	else if (var_b_index > (int)stack_b->size / 2 && var_b_index > var_a_index)
	{
		if (calcul_total_moves(var_a_index, var_b_index) < calcul_total_moves(node->var_a, node->var_b))
			node->var_b = var_b_index;
	}
}

/* -------------------------------------------------------------------------- */

void	push_lowest_to_head(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		index;
	int		i;
	int		op;

	i = 0;
	node = get_lowest_value_node(stack_a);
	index = get_node_index(node, stack_a);
	if ((t_uint)index > (stack_a->size / 2))
		op = RRA;
	else
		op = RA;
	while (node != stack_a->head && i++ <= my_abs(index))
		check_exec_op(op, stack_a, stack_b);
}

/* -------------------------------------------------------------------------- */

static void	exec_rotation(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	if (node->var_a > 0 && node->var_b <= 0)
	{
		check_exec_op(RA, stack_a, stack_b);
		node->var_a -= 1;
	}
	else if (node->var_b > 0 && node->var_a <= 0)
	{
		check_exec_op(RB, stack_a, stack_b);
		node->var_b -= 1;
	}
	else if (node->var_b > 0 && node->var_a > 0)
	{
		check_exec_op(RR, stack_a, stack_b);
		node->var_a -= 1;
		node->var_b -= 1;
	}
}

/* -------------------------------------------------------------------------- */

static void	exec_rev_rotation(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	if (node->var_a < 0 && node->var_b >= 0)
	{
		check_exec_op(RRA, stack_a, stack_b);
		node->var_a += 1;
	}
	else if (node->var_b < 0 && node->var_a >= 0)
	{
		check_exec_op(RRB, stack_a, stack_b);
		node->var_b += 1;
	}
	else if (node->var_a < 0 && node->var_b < 0)
	{
		check_exec_op(RRR, stack_a, stack_b);
		node->var_a += 1;
		node->var_b += 1;
	}
}

/* -------------------------------------------------------------------------- */

void	exec_condit_push(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	while (node->var_a || node->var_b)
	{
		exec_rotation(node, stack_a, stack_b);
		exec_rev_rotation(node, stack_a, stack_b);
	}
	if (node->var_a + node->var_b == 0)
		check_exec_op(PA, stack_a, stack_b);
}

/* -------------------------------------------------------------------------- */
