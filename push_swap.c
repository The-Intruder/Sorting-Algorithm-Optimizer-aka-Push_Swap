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

static void	print_stack(t_stack *stack)
{
	t_uint	i;
	t_node	**node;

	i = 0;
	node = &stack->head;
	ft_printf("%s|||||||||||||||||||||||||%s\n", BLD, NC);
	ft_putchar_fd('\n', 1);
	while (i < stack->size)
	{
		printf("%so-----------------------o\n| (%s%u%s): %s%p\t%s|\n" \
			"o-----------------------o\n| %sprev: %14p\t%s|\n" \
			"| %sindx: %14u\t%s|\n| %snmbr: %14d\t%s|\n| %snext: %14p\t%s|\n" \
			"o-----------------------o%s\n", BLU, CYN, i + 1, BLU, MGN, *node, \
			BLU, YEL, (*node)->prev, BLU, RED, (*node)->indx, BLU, BLD, \
			(*node)->nmbr, BLU, GRN, (*node)->next, BLU, NC);
		if (i < stack->size - 1)
			printf("\t||\t/\\\n\t\\/\t||\n");
		node = &(*node)->next;
		++i;
	}
	ft_putchar_fd('\n', 1);
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		err;

	if (handle_err(argc, argv))
		return (-1);
	err = init_stack(&stack_a, argc, argv);
	if (err)
		return (-1);
	ft_bzero(&stack_b, sizeof(stack_b));
	print_stack(&stack_a);
	check_exec_op(PB, &stack_a, &stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	return (0);
}

/* -------------------------------------------------------------------------- */