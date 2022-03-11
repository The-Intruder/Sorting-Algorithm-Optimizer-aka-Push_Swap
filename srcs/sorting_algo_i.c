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

static int	count_moves_to_head(t_uint index, t_node *node, t_stack *stack)
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

int	push_non_lis_to_stackb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	update_best_moves_to_head(t_stack *stack)
{
	t_uint	i;
	t_node	*node;

	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (!node->var_c)
			node->var_a = count_moves_to_head(i, node, stack);
		node->var_b = 0;
		node = node->next;
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
