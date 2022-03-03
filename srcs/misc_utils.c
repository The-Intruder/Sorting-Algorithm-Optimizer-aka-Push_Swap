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

void	patch_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size > 0)
	{
		if (stack_a->head)
			stack_a->head->prev = NULL;
		if (stack_a->tail)
			stack_a->tail->next = NULL;
	}
	if (stack_b && stack_b->size > 0)
	{
		if (stack_b->head)
			stack_b->head->prev = NULL;
		if (stack_b->tail)
			stack_b->tail->next = NULL;
	}
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
