/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_ii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static void	exec_rotation(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	if (node->var_a > 0 && node->var_b <= 0)
	{
		check_exec_op(RA, stack_a, stack_b);
		node->var_a -= 1;
	}
	else if (node->var_b > 0 && node->var_a <= 0)
	{
		check_exec_op(RB, stack_a, stack_b);
		node->var_b -= 1;
	}
	else if (node->var_b > 0 && node->var_a > 0)
	{
		check_exec_op(RR, stack_a, stack_b);
		node->var_a -= 1;
		node->var_b -= 1;
	}
}

/* -------------------------------------------------------------------------- */

static void	exec_rev_rotation(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	if (node->var_a < 0 && node->var_b >= 0)
	{
		check_exec_op(RRA, stack_a, stack_b);
		node->var_a += 1;
	}
	else if (node->var_b < 0 && node->var_a >= 0)
	{
		check_exec_op(RRB, stack_a, stack_b);
		node->var_b += 1;
	}
	else if (node->var_a < 0 && node->var_b < 0)
	{
		check_exec_op(RRR, stack_a, stack_b);
		node->var_a += 1;
		node->var_b += 1;
	}
}

/* -------------------------------------------------------------------------- */

void	exec_condit_push(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	while (node->var_a || node->var_b)
	{
		exec_rotation(node, stack_a, stack_b);
		exec_rev_rotation(node, stack_a, stack_b);
	}
	if (node->var_a + node->var_b == 0)
		check_exec_op(PA, stack_a, stack_b);
}

/* -------------------------------------------------------------------------- */
