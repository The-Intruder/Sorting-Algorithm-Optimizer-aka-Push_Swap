/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_filtering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static int	count_moves_to_head(t_uint index, t_stack *stack)
{
	if (index > (stack->size / 2))
		return (stack->size - index);
	else if (index <= (stack->size / 2))
		return (index);
	return (-1);
}

/* -------------------------------------------------------------------------- */

static int	calcul_moves_to_stackb(t_stack *stack)
{
	t_uint	i;
	t_node	*node;

	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (node->var_c)
			node->var_a = count_moves_to_head(i, stack);
		else
			node->var_a = -1;
		node->var_b = 0;
		node = node->next;
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	get_lowst_moves_node(t_node **node, t_stack *stack)
{
	t_node	*tracer;
	t_uint	true_index;
	t_uint	i;

	if (!stack || stack->size == 0)
		return (-1);
	*node = NULL;
	tracer = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (!(*node) && tracer->var_c)
		{
			*node = tracer;
			true_index = i;
		}
		if (tracer->var_c && tracer->var_a >= 0 && tracer->var_a < (*node)->var_a)
		{
			*node = tracer;
			true_index = i;
		}
		tracer = tracer->next;
		i++;
	}
	return (true_index);
}

/* -------------------------------------------------------------------------- */

static int non_lis_count(t_stack *stack)
{
	t_node	*node;
	t_uint	i;
	int		count;

	count = 0;
	i = 0;
	node = stack->head;
	while (i < stack->size)
	{
		if (node->var_c)
			++count;
		node = node->next;
		i++;
	}
	return (count);
}

/* -------------------------------------------------------------------------- */

int	push_non_lis_node_to_stackb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		index;
	int		count;
	int		op;
	
	node = NULL;
	count = non_lis_count(stack_a);
	calcul_moves_to_stackb(stack_a);
	//ft_printf("%d\n", count);
	while (count)
	{
		index = get_lowst_moves_node(&node, stack_a);
		if ((t_uint)index <= (stack_a->size / 2))
			op = RA;
		else if ((t_uint)index > (stack_a->size / 2))
			op = RRA;
		while (stack_a->head != node)
			exec_print_op(op, stack_a, stack_b, 1);
		if (stack_a->head == node)
			exec_print_op(PB, stack_a, stack_b, 1);
		count--;
		calcul_moves_to_stackb(stack_a);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
