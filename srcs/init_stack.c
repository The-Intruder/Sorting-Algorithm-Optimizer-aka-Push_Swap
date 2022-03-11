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

int	trim_unwanted_chars(char **new_argv)
{
	int		i;
	char	*dummy_ptr;

	i = 0;
	while (new_argv[i])
	{
		dummy_ptr = new_argv[i];
		new_argv[i] = ft_strtrim(new_argv[i], "\t\n\v\f\r");
		if (!new_argv[i++])
			return (-1);
		free(dummy_ptr);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static void	free_newly_created_argv(char **new_argv)
{
	int	i;

	if (!new_argv)
		return ;
	i = 0;
	while (new_argv[i])
		free(new_argv[i++]);
	free(new_argv);
}

/* -------------------------------------------------------------------------- */

static char	**get_patched_argv(int argc, char **argv)
{
	int		i;
	char	*argv_concat;
	void	*dummy_ptr;
	char	**new_argv;

	i = 1;
	argv_concat = (char *)ft_calloc(1, sizeof(char));
	while (i < argc)
	{
		dummy_ptr = argv_concat;
		argv_concat = ft_strjoin(argv_concat, argv[i++]);
		free(dummy_ptr);
		dummy_ptr = argv_concat;
		argv_concat = ft_strjoin(argv_concat, " ");
		free(dummy_ptr);
	}
	new_argv = ft_split(argv_concat, ' ');
	if (trim_unwanted_chars(new_argv))
		return (free_newly_created_argv(new_argv), free(argv_concat), NULL);
	return (free(argv_concat), new_argv);
}

/* -------------------------------------------------------------------------- */

static t_node	*init_stack_node(char *asci_nbr)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->value = ft_atoi(asci_nbr);
	node->var_a = 1;
	node->var_b = -1;
	node->var_c = 0;
	node->next = NULL;
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	link_stack_nodes(t_stack *stack, char **argv)
{
	t_node	*node;
	int		i;

	i = 0;
	node = NULL;
	while (argv[i])
	{
		node = init_stack_node(argv[i]);
		/* Add protection for all allocated nodes */
		if (stack->tail)
		{
			stack->tail->next = node;
			node->prev = stack->tail;
			node->next = stack->head;
		}
		else if (i == 0)
			stack->head = node;
		stack->tail = node;
		++i;
	}
	stack->size = i;
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_stack(t_stack	*stack, int argc, char **argv)
{
	char	**new_argv;
	int		err;

	err = 0;
	new_argv = get_patched_argv(argc, argv);
	if (!new_argv || handle_err(argc, new_argv))
		return (-1);
	err = link_stack_nodes(stack, new_argv);
	if (err)
		return (-1);
	patch_stack(stack);
	free_newly_created_argv(new_argv);
	return (0);
}

/* -------------------------------------------------------------------------- */
