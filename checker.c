/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* -------------------------------------------------------------------------- */

static int	str_to_int_op_ii(char *str_op)
{
	if (!ft_strcmp(str_op, "ra"))
		return (RA);
	else if (!ft_strcmp(str_op, "rb"))
		return (RB);
	else if (!ft_strcmp(str_op, "rr"))
		return (RR);
	else if (!ft_strcmp(str_op, "rra"))
		return (RRA);
	else if (!ft_strcmp(str_op, "rrb"))
		return (RRB);
	else if (!ft_strcmp(str_op, "rrr"))
		return (RRR);
	else
		return (-1);
}

/* -------------------------------------------------------------------------- */

static int	str_to_int_op_i(char *str_op)
{
	if (!ft_strcmp(str_op, "sa"))
		return (SA);
	else if (!ft_strcmp(str_op, "sb"))
		return (SB);
	else if (!ft_strcmp(str_op, "ss"))
		return (SS);
	else if (!ft_strcmp(str_op, "pa"))
		return (PA);
	else if (!ft_strcmp(str_op, "pb"))
		return (PB);
	else
		return (str_to_int_op_ii(str_op));
}

/* -------------------------------------------------------------------------- */

static int	execute_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*str_op;
	void	*dummy_ptr;
	int		int_op;

	str_op = get_next_line(0, 1);
	while (str_op)
	{
		dummy_ptr = str_op;
		str_op = ft_strtrim(str_op, "\n");
		free(dummy_ptr);
		int_op = str_to_int_op_i(str_op);
		if (int_op == -1)
			return (ft_printf("%sERROR%s\n", RED, NC), -1);
		check_exec_op(int_op, stack_a, stack_b, 0);
		dummy_ptr = str_op;
		str_op = get_next_line(0, 1);
		free(dummy_ptr);
	}
	if (!stack_b->size && stack_is_sorted(stack_a))
		ft_printf("%sOK%s\n", GRN, NC);
	else
		ft_printf("%sKO%s\n", RED, NC);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		err;

	if (argc == 1)
		return (0);
	reset_stack(&stack_a);
	reset_stack(&stack_b);
	err = init_stack(&stack_a, argc, argv);
	if (err < 0 || err == 3)
		return (0);
	err = execute_operations(&stack_a, &stack_b);
	if (err)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
