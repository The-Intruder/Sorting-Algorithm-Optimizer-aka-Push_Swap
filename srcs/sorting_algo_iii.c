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

int	calcul_number_diff(int nb1, int nb2)
{
	if (are_same_sign(nb1, nb2))
	{
		if (abs(nb1) > abs(nb2))
			return (abs(nb1) - abs(nb2));
		else
			return (abs(nb2) - abs(nb1));
	}
	else
		return (abs(nb1) + abs(nb2));
}

/* -------------------------------------------------------------------------- */

int	calcul_total_moves(int var_a, int var_b)
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

int	get_index_from_head_moves(int moves, int stack_size)
{
	int	index;

	index = moves;
	if (moves < 0 )
		index = stack_size + moves;
	return (index);
}

/* -------------------------------------------------------------------------- */

int	get_node_index(t_node *node, t_stack *stack)
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

int	count_head_distance(int index, t_stack *stack)
{
	if ((t_uint)index > (stack->size / 2))
		return ((stack->size - index) * -1);
	else
		return (index);
}

/* -------------------------------------------------------------------------- */
