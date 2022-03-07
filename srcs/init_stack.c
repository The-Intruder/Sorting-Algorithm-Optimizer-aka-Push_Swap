/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

static t_node	*init_stack_node(char *asci_nbr)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node -> prev = NULL;
	node -> value = ft_atoi(asci_nbr);
	node -> subseq_len = 1;
	node -> prev_indx = -1;
	node -> next = NULL;
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	link_stack_nodes(t_stack *stack, int argc, char **argv)
{
	t_node	*node;
	int		i;

	i = 1;
	node = NULL;
	while (i < argc)
	{
		node = init_stack_node(argv[i]);
		/* Add protection for all allocated nodes */
		if (stack->tail)
		{
			stack->tail->next = node;
			node->prev = stack->tail;
		}
		else if (i == 1)
			stack->head = node;
		stack->tail = node;
		++i;
	}
	stack->size = --i;
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_stack(t_stack	*stack, int argc, char **argv)
{
	if (link_stack_nodes(stack, argc, argv))
		return (-1);
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	return (0);
}

/* -------------------------------------------------------------------------- */
