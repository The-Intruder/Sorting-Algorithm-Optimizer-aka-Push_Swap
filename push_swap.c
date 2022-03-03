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

/* ========================================================================== */
/* ========================== TESTING-PHASE FUNCTIONS ======================= */

static void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_uint	i;
	t_node	**node_a;
	t_node	**node_b;
	int		len;

	i = 0;
	node_a = &stack_a->head;
	node_b = &stack_b->head;
	len = 0;
	ft_putchar_fd('\n', 1);
	while (*node_a || *node_b)
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
		if (*node_a)
			ft_printf("%so-----------------------o\t\t||\t\t", BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("o-----------------------o\n");
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("| (%s%u%s): %s%14p\t%s|\t\t||\t\t", \
				CYN, i + 1, BLU, MGN, *node_a, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("| (%s%u%s): %s%14p\t%s|\n", \
				CYN, i + 1, BLU, MGN, *node_b, BLU);
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("o-----------------------o\t\t||\t\t");
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("o-----------------------o\n");
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("| %sprev: %14p\t%s|\t\t||\t\t", YEL, (*node_a)->prev, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("| %sprev: %14p\t%s|\n", YEL, (*node_b)->prev, BLU);
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("| %sindx: %14u\t%s|\t\t||\t\t", RED, (*node_a)->indx, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("| %sindx: %14u\t%s|\n", RED, (*node_b)->indx, BLU);
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("| %snmbr: %14d\t%s|\t\t||\t\t", BLD, (*node_a)->nmbr, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("| %snmbr: %14d\t%s|\n", BLD, (*node_b)->nmbr, BLU);
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("| %snext: %14p\t%s|\t\t||\t\t", GRN, (*node_a)->next, BLU);
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("| %snext: %14p\t%s|\n", GRN, (*node_b)->next, BLU);
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			ft_printf("o-----------------------o\t\t||\t\t");
		else
			ft_printf("%s\t\t\t\t\t||\t\t", BLU);
		if (*node_b)
			ft_printf("o-----------------------o%s\n", NC);
		else
			ft_putchar_fd('\n', 1);
		if (i + 1 < stack_a->size)
			ft_printf("%s\t||\t/\\\t\t\t||%s", BLU, NC);
		else
			ft_printf("%s\t\t\t\t\t||%s", BLU, NC);
		if (i + 1 < stack_b->size)
			ft_printf("%s\t\t\t||\t/\\%s\n", BLU, NC);
		else
			ft_putchar_fd('\n', 1);
		if (i + 1 < stack_a->size)
			ft_printf("%s\t\\/\t||\t\t\t||%s", BLU, NC);
		else
			ft_printf("%s\t\t\t\t\t||%s", BLU, NC);
		if (i + 1 < stack_b->size)
			ft_printf("%s\t\t\t\\/\t||%s\n", BLU, NC);
		else
			ft_putchar_fd('\n', 1);
		if (*node_a)
			node_a = &(*node_a)->next;
		if (*node_b)
			node_b = &(*node_b)->next;
		++i;
	}
	ft_putchar_fd('\n', 1);
}

/* ========================================================================== */

static void	exec_print_op(int op_mask, t_stack *stack_a, t_stack *stack_b)
{
	system("clear");
	if (op_mask & SA)
		ft_printf("%s\t\t\t\t\t\bSWAP_A%s", BLD, NC);
	else if (op_mask & SB)
		ft_printf("%s\t\t\t\t\t\bSWAP_B%s", BLD, NC);
	else if (op_mask & SS)
		ft_printf("%s\t\t\t\t\t\bSWAP_S%s", BLD, NC);
	else if (op_mask & PA)
		ft_printf("%s\t\t\t\t\t\bPUSH_A%s", BLD, NC);
	else if (op_mask & PB)
		ft_printf("%s\t\t\t\t\t\bPUSH_B%s", BLD, NC);
	else if (op_mask & RA)
		ft_printf("%s\t\t\t\t\tROTATE_A%s", BLD, NC);
	else if (op_mask & RB)
		ft_printf("%s\t\t\t\t\t\b\bROTATE_B%s", BLD, NC);
	else if (op_mask & RR)
		ft_printf("%s\t\t\t\t\t\b\bROTATE_R%s", BLD, NC);
	else if (op_mask & RRA)
		ft_printf("%s\t\t\t\t\t\b\b\bRevROTATE_A%s", BLD, NC);
	else if (op_mask & RRB)
		ft_printf("%s\t\t\t\t\t\b\b\bRevROTATE_B%s", BLD, NC);
	else if (op_mask & RRR)
		ft_printf("%s\t\t\t\t\t\b\b\bRevROTATE_R%s", BLD, NC);
	if (op_mask)
		check_exec_op(op_mask, stack_a, stack_b);
	print_stack(stack_a, stack_b);
	sleep(3);
}

/* ========================================================================== */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		err;

	reset_stack(&stack_a, &stack_b);
	system("clear");
	if (handle_err(argc, argv))
		return (-1);
	err = init_stack(&stack_a, argc, argv);
	if (err)
		return (-1);
	exec_print_op(0, &stack_a, &stack_b);
	exec_print_op(PB, &stack_a, &stack_b);
	exec_print_op(RRA, &stack_a, &stack_b);
	exec_print_op(PB, &stack_a, &stack_b);
	exec_print_op(SB, &stack_a, &stack_b);
	exec_print_op(PB, &stack_a, &stack_b);
	exec_print_op(RR, &stack_a, &stack_b);
	exec_print_op(PB, &stack_a, &stack_b);
	exec_print_op(SA, &stack_a, &stack_b);
	exec_print_op(PB, &stack_a, &stack_b);
	exec_print_op(RB, &stack_a, &stack_b);
	exec_print_op(PA, &stack_a, &stack_b);
	exec_print_op(SS, &stack_a, &stack_b);
	exec_print_op(PA, &stack_a, &stack_b);
	exec_print_op(RRR, &stack_a, &stack_b);
	exec_print_op(0, &stack_a, &stack_b);
	return (0);
}

/* -------------------------------------------------------------------------- */
