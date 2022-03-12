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

static t_node	*get_best_node(t_stack *stack)
{
	t_uint	i;
	t_node	*node;
	t_node	*ref_node;

	i = 0;
	node = stack->head;
	ref_node = stack->head->next;
	while (i++ < stack->size)
	{
		if (ref_node->var_c < node->var_c)
			node = ref_node;
		ref_node = ref_node->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

static void	calcul_best_prev_node(t_stack *stack, int value)
{
	t_uint	i;
	t_node	*node;
	int		moves;

	i = 0;
	node = stack->head;
	moves = 0;
	while (i++ < stack->size)
	{
		node->var_c = node->value - value;
		node = node->next;
	}
}

/* -------------------------------------------------------------------------- */

static int	get_moves_to_head(t_uint index, t_stack *stack)
{
	t_uint	index
	if (index <= (stack->size / 2))
		return (index);
	return ((stack->size - index) * -1);
}

/* -------------------------------------------------------------------------- */

static void calculate_total_sorting_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_uint	i;
	t_node	*node;

	i = 0;
	node = stack_b->head;
	while (i < stack_b->size)
	{
		node->var_a = get_moves_to_head(i, stack_b);
		node->var_b = count_sorting_moves(stack_a, node->value);
		node->var_c = -1;
		if (node->var_a >= 0 && node->var_b >= 0)
			node->var_c = get_node_position(i, stack_a);
		node = node->next;
		++i;
	}
}

/* -------------------------------------------------------------------------- */

int	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		index;
	int		op;

	while (stack_b->size)
	{
		calculate_total_sorting_moves(stack_a, stack_b);

	}
}

/* -------------------------------------------------------------------------- */
