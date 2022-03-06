/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_incr_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static t_node	*get_node_addr(t_stack *stack, t_uint index)
{
	t_uint	i;
	t_node	*node;

	if (!stack || !stack->size || !stack->head || index >= stack->size)
		return (NULL);
	i = 0;
	node = stack->head;
	while (i++ < index && node)
		node = node->next;
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	get_node_nmbr(t_stack *stack, t_uint index)
{
	t_uint	i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i++ < index && node->next)
		node = node->next;
	return (node->nmbr);
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	apply_lis_algo(t_stack *stack)
{
	t_node	*node_i;
	t_node	*node_j;
	t_uint	i;
	t_uint	j;

	i = 1;
	while (i < stack->size)
	{
		node_i = get_node_addr(stack, i);
		j = 0;
		while (j < i)
		{
			node_j = get_node_addr(stack, j);
			if (node_j->nmbr < node_i->nmbr)
			{
				if (node_i->sbln < node_j->sbln + 1)
				{
					node_i->sbln = node_j->sbln + 1;
					node_i->indx = j;
				}
				else if (node_i->sbln == node_j->sbln + 1)
				{
					if (node_j->nmbr < get_node_nmbr(stack, node_i->indx))
					{
						node_i->sbln = node_j->sbln + 1;
						node_i->indx = j;
					}
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */