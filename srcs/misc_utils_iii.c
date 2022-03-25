/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_iii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

void	free_newly_created_argv(char **new_argv)
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

int	trim_unwanted_chars(char **new_argv)
{
	int		i;
	char	*dummy_ptr;

	i = 0;
	while (new_argv[i])
	{
		dummy_ptr = new_argv[i];
		new_argv[i] = ft_strtrim(new_argv[i], " ");
		if (!new_argv[i] || !new_argv[i][0])
			return (p_err(" "), free_newly_created_argv(new_argv), \
				exit(-1), 0);
		free(dummy_ptr);
		i++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	arg_is_valid(char *argv)
{
	int	i;
	int	sign;
	int	digit;

	i = -1;
	sign = 0;
	digit = 0;
	while (argv[++i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			sign += 1;
		else if (ft_isdigit(argv[i]))
			digit += 1;
		else if (argv[i] != '-' && argv[i] != '+' && argv[i] != ' ' && \
			!ft_isdigit(argv[i]))
			return (-1);
	}
	if (digit == 0 || sign > 1)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */

static void	free_stack(t_stack *stack)
{
	t_uint	i;
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

void	free_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(0);
}

/* -------------------------------------------------------------------------- */
