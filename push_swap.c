/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* -------------------------------------------------------------------------- */

void	free_stack(t_stack	*stack)
{
	int		i;
	t_node	*ptr;
	t_node	*node;

	if (stack->size == 0)
		return ;
	i = 0;
	node = stack->head;
	while (i++ < stack->size)
	{
		ptr = node;
		node = node->next;
		free(ptr);
	}
}

/* -------------------------------------------------------------------------- */

void	sort_with_index(t_stack *stack)
{
	t_node	*node_i;
	t_node	*node_j;
	t_uint	i;
	t_uint	j;

	i = 0;
	node_i = stack->head;
	while (i++ < stack->size)
	{
		node_i->index = 0;
		node_j = node_i->next;
		j = 0;
		while (j++ < stack->size)
		{
			if (node_i->value > node_j->value)
				node_i->index += 1;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_node	*lis_tail;
	int		err;

	if (argc <= 2)
		return (0);
	reset_stack(&stack_a);
	reset_stack(&stack_b);
	err = init_stack(&stack_a, argc, argv);
	if (err < 0)
		return (err);
	if (stack_a.size == 3)
		return (handle_exeptions(&stack_a));
	else if (err == 3)
		return (0);
	if (!stack_b.size && stack_is_sorted(&stack_a))
		return (0);
	sort_with_index(&stack_a);
	lis_tail = apply_lis_algo(&stack_a);
	push_non_lis_node_to_stackb(&stack_a, &stack_b);
	sort_numbers(&stack_a, &stack_b);
	return (0);
}

/* -------------------------------------------------------------------------- */
