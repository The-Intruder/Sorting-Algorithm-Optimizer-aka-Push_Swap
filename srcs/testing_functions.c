/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_uint	i;
	t_node	*node_a;
	t_node	*node_b;
	int		len;

	i = 0;
	node_a = stack_a->head;
	node_b = stack_b->head;
	len = 0;
	system("clear");
	ft_putchar_fd('\n', 1);
	while (i < stack_a->size || i < stack_b->size)
	{
		if (i == 0)
		{
			ft_printf("%s==========================================="
				"======================================%s\n",
				BLU, NC);
			ft_printf("%s|=> %sSTACK_A Size: %3u%s <=|\t\t|", \
				BLU, BLD, stack_a->size, BLU);
			ft_printf("|\t\t|=> %sSTACK_B Size: %3u%s <=|%s\n", \
				BLD, stack_b->size, BLU, NC);
		}
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("%so-----------------------o\t\t||\t\t", BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("o-----------------------o\n");
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| (%s%u%s): %s%14p\t%s|\t\t||\t\t", \
				CYN, i + 1, BLU, MGN, node_a, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| (%s%u%s): %s%14p\t%s|\n", \
				CYN, i + 1, BLU, MGN, node_b, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("o-----------------------o\t\t||\t\t");
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("o-----------------------o\n");
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %sprev: %14p\t%s|\t\t||\t\t", YEL, node_a->prev, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %sprev: %14p\t%s|\n", YEL, node_b->prev, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %svalue: %13d\t%s|\t\t||\t\t", RED, node_a->value, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %svalue: %13d\t%s|\n", RED, node_b->value, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %svar_a: %13d\t%s|\t\t||\t\t", BLD, node_a->var_a, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %svar_a: %13d\t%s|\n", BLD, node_b->var_a, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %svar_b: %13d\t%s|\t\t||\t\t", BLD, node_a->var_b, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %svar_b: %13d\t%s|\n", BLD, node_b->var_b, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %svar_c: %13d\t%s|\t\t||\t\t", BLD, node_a->var_c, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %svar_c: %13d\t%s|\n", BLD, node_b->var_c, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %splis: %14p\t%s|\t\t||\t\t", CYN, node_a->prev_lis, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %splis: %14p\t%s|\n", CYN, node_b->prev_lis, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %snlis: %14p\t%s|\t\t||\t\t", CYN, node_a->next_lis, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %sn_is:% 14p\t%s|\n", CYN, node_b->next_lis, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("| %snext: %14p\t%s|\t\t||\t\t", GRN, node_a->next, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("| %snext: %14p\t%s|\n", GRN, node_b->next, BLU);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i < stack_a->size)
			ft_printf("o-----------------------o\t\t||\t\t");
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (i < stack_b->size)
			ft_printf("o-----------------------o%s\n", NC);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i + 1 < stack_a->size)
			ft_printf("%s\t\\/\t/\\\t\t\t||%s", BLU, NC);
		else
			ft_printf("%s\t\t\t\t\t||%s", BLU, NC);
		if (i + 1 < stack_b->size)
			ft_printf("%s\t\t\t\\/\t/\\%s\n", BLU, NC);
		else
			ft_putchar_fd('\n', 1);
		/*--------------------------------------------------------------------*/
		if (i + 1 < stack_a->size)
			node_a = node_a->next;
		if (i + 1 < stack_b->size)
			node_b = node_b->next;
		++i;
	}
	ft_putchar_fd('\n', 1);
	sleep(2);
}

/* -------------------------------------------------------------------------- */
