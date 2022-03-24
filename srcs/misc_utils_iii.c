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
			return (p_err(" "), exit(-1), -1);
		free(dummy_ptr);
		i++;
	}
	return (0);
}

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
		{
			sign += 1;
			continue ;
		}
		if (ft_isdigit(argv[i]))
		{
			digit += 1;
			continue ;
		}
		if (argv[i] != '-' && argv[i] != '+' && argv[i] != ' ' && \
			!ft_isdigit(argv[i]))
			return (-1);
	}
	if (digit == 0 || sign > 1)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
