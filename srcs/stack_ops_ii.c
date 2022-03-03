/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_ii.c                                     :+:      :+:    :+:   */
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

/* -------------------------------------------------------------------------- */

static int	check_exec_op_i(int op_mask, t_stack *stack_a, t_stack *stack_b)
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

int	check_exec_op(int op_mask, t_stack *stack_a, t_stack *stack_b)
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
		err = check_exec_op_i(op_mask, stack_a, stack_b);
	return (err);
}

/* -------------------------------------------------------------------------- */