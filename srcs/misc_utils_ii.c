/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_ii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

int	is_negative(int nbr)
{
	if (nbr < 0)
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	is_positive(int nbr)
{
	if (nbr >= 0)
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	are_same_sign(int nbr1, int nbr2)
{
	if ((is_positive(nbr1) && is_positive(nbr2)) ||
		(is_negative(nbr1) && is_negative(nbr2)))
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	stack_is_sorted(t_stack *stack)
{
	t_uint	i;
	t_node	*node;

	if (stack->size < 2)
		return (1);
	i = 0;
	node = stack->head;
	while ((i++) + 1 < stack->size)
	{
		if (node->next->value < node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */
