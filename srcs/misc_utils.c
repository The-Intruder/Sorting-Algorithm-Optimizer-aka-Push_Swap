/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

void	reset_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_a->head = NULL;
		stack_a->size = 0;
		stack_a->tail = NULL;
	}
	if (stack_b)
	{
		stack_b->head = NULL;
		stack_b->size = 0;
		stack_b->tail = NULL;
	}
}

/* -------------------------------------------------------------------------- */

void	patch_stack(t_stack *stack)
{
	if (stack && stack->size > 0)
	{
		if (stack->head && stack->tail)
		{
			stack->head->prev = stack->tail;
			stack->tail->next = stack->head;
		}
	}
}

/* -------------------------------------------------------------------------- */

t_node	*get_smallest_number(t_stack *stack)
{
	t_node	*tracer;
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->head;
	tracer = stack->head->next;
	while (tracer)
	{
		if (tracer->value < node->value)
			node = tracer;
		tracer = tracer->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
