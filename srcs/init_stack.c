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

static int	is_all_digit(char *str)
{
	while (*str)
	{
		if (*str != '-' && (*str < '0' || *str > '9'))
			return (1);
		++str;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

// static void	check_duplicate(argc, argv)
// {
// 	int	i;

// 	i = 1;
// 	while (i < argv)

// }

/* -------------------------------------------------------------------------- */

static t_node	*init_stack_node(char *asci_nbr)
{
	t_node	*node;

	node = (t_node *)calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node -> prev = NULL;
	node -> indx = 0;
	node -> nmbr = atoi(asci_nbr);
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
	stack->head = NULL;
	while (i < argc)
	{
		if (is_all_digit(argv[i]))
			return (1);
		node = init_stack_node(argv[i]);
		if (stack->head)
		{
			stack->head->prev = node;
			node->next = stack->head;
		}
		if (i == 1)
			stack->tail = node;
		else
			stack->head = node;
		stack->head = node;
		++i;
	}
	stack->size = --i;
	return (0);
}

/* -------------------------------------------------------------------------- */

t_stack	*init_stack(int argc, char **argv)
{
	int		err;
	t_stack	*stack;

	stack = (t_stack *)calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	err = link_stack_nodes(stack, argc, argv);
	if (err)
		return (NULL);
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	return (stack);
}

/* -------------------------------------------------------------------------- */
