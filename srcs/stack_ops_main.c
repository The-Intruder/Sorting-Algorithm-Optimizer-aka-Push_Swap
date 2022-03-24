/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static void	print_instruction(int op_mask)
{
	if (op_mask & SA)
		ft_printf("sa\n");
	else if (op_mask & SB)
		ft_printf("sb\n");
	else if (op_mask & SS)
		ft_printf("ss\n");
	else if (op_mask & PA)
		ft_printf("pa\n");
	else if (op_mask & PB)
		ft_printf("pb\n");
	else if (op_mask & RA)
		ft_printf("ra\n");
	else if (op_mask & RB)
		ft_printf("rb\n");
	else if (op_mask & RR)
		ft_printf("rr\n");
	else if (op_mask & RRA)
		ft_printf("rra\n");
	else if (op_mask & RRB)
		ft_printf("rrb\n");
	else if (op_mask & RRR)
		ft_printf("rrr\n");
}

/* -------------------------------------------------------------------------- */

static int	check_exec_op_ii(int op_mask, t_stack *stack_a, t_stack *stack_b)
{
	int	err;

	err = 0;
	if (op_mask & RB)
		err = rotate_stack(stack_b);
	else if (op_mask & RR)
	{
		err = rotate_stack(stack_a);
		err = rotate_stack(stack_b);
	}
	else if (op_mask & RRA)
		err = rev_rotate_stack(stack_a);
	else if (op_mask & RRB)
		err = rev_rotate_stack(stack_b);
	else if (op_mask & RRR)
	{
		err = rev_rotate_stack(stack_a);
		err = rev_rotate_stack(stack_b);
	}
	return (err);
}

/* -------------------------------------------------------------------------- */

int	check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b, int print)
{
	int	err;

	err = 0;
	if (op_mask & SA)
		err = swap_stack(stack_a);
	else if (op_mask & SB)
		err = swap_stack(stack_b);
	else if (op_mask & SS)
	{
		err = swap_stack(stack_a);
		err = swap_stack(stack_b);
	}
	else if (op_mask & PA)
		err = push_stack(stack_b, stack_a);
	else if (op_mask & PB)
		err = push_stack(stack_a, stack_b);
	else if (op_mask & RA)
		err = rotate_stack(stack_a);
	else
		err = check_exec_op_ii(op_mask, stack_a, stack_b);
	if (print)
		print_instruction(op_mask);
	return (err);
}

/* -------------------------------------------------------------------------- */
