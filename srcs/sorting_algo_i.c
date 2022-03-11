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

// t_stack	*copy_stack(t_stack *stack)
// {
// 	char	**val_arr;
// 	t_node	*node;
// 	t_stack	*cp_stack;
// 	int		i;

// 	val_arr = (int *)ft_calloc(stack->size, sizeof(int));
// 	if (!val_arr)
// 		return (NULL);		// Print an error here
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		node = get_node_addr(stack->head, stack->size, i);
// 		val_arr[i++] = ft_itoa(node->value);
// 	}
// 	cp_stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
// 	if (!cp_stack)
// 		return (NULL);		// Print an error here
// 	if (init_stack(cp_stack, stack->size, val_arr))
// 		return (NULL);
// 	return (cp_stack);
// }

/* -------------------------------------------------------------------------- */

static int	count_moves_lis(t_uint index, t_node *node, t_stack *stack)
{
	t_uint	i;
	t_node	*tracer;
	int		node_pos;

	i = 0;
	tracer = node;
	if (index > (stack->size / 2))
		node_pos = LH;
	else if (index <= (stack->size / 2))
		node_pos = UH;
	while (i < stack->size && stack->head != tracer)
	{
		if (node_pos & LH)
			tracer = tracer->next;
		else if (node_pos & UH)
			tracer = tracer->prev;
		i++;
	}
	return ((int)i);
}

/* -------------------------------------------------------------------------- */

static int	update_best_moves_lis(t_stack *stack)
{
	t_uint	i;
	t_node	*node;

	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (node->var_c)
			node->var_a = count_moves_lis(i, node, stack);
		node->var_b = 0;
		node = node->next;
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	get_lowst_moves_addr_index(t_node **node, t_stack *stack)
{
	t_node	*tracer;
	int	i;

	if (!stack || stack->size == 0)
		return (-1);
	*node = stack->head;
	tracer = stack->head->next;
	i = 0;
	while ((t_uint)i < stack->size)
	{
		if (tracer->var_c && tracer->var_a < (*node)->var_a)
			*node = tracer;
		tracer = tracer->next;
		i++;
	}
	return (i);
}

/* -------------------------------------------------------------------------- */

static int get_non_lis_nodes_count(t_stack *stack)
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
	int		op;
	
	node = NULL;
	update_best_moves_lis(stack_a);
	while (get_non_lis_nodes_count(stack_a))
	{
		index = get_lowst_moves_addr_index(&node, stack_a);
		if ((t_uint)index <= (stack_a->size / 2))
			op = RA;
		else if ((t_uint)index > (stack_a->size / 2))
			op = RRA;
		while (stack_a->head != node)
			exec_print_op(op, stack_a, stack_b);
		exec_print_op(PB, stack_a, stack_b);
		update_best_moves_lis(stack_a);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
