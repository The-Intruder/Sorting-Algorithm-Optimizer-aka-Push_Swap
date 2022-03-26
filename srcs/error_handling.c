/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static int	is_all_valid_digits(char **argv)
{
	int	i;
	int	j;
	int	sign;
	int	digit;

	i = -1;
	while (argv[++i])
	{
		sign = 0;
		digit = 0;
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '+' || argv[i][j] == '-'))
				++sign;
			else if (ft_isdigit(argv[i][j]))
				++digit;
			else
				return (-1);
		}
		if (sign && !digit)
			return (-1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	check_duplicate(char **argv)
{
	int	i[2];
	int	j[2];

	i[0] = 0;
	while (argv[i[0]])
	{
		j[0] = i[0];
		i[1] = ft_atoi(argv[i[0]]);
		while (argv[++j[0]])
		{
			j[1] = ft_atoi(argv[j[0]]);
			if (i[1] == j[1])
				return (-1);
		}
		++i[0];
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	check_min_max_int(char **argv)
{
	int		i;
	int		j;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			++j;
		while (argv[i][j] == '0')
			++j;
		if (ft_strlen(&argv[i][j]) > 10)
			return (-1);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (-1);
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	handle_err(int argc, char **new_argv)
{
	int	new_argc;

	new_argc = 0;
	argc = 0;
	while (new_argv[new_argc])
		++new_argc;
	if (is_all_valid_digits(new_argv))
		return (p_err(""), -1);
	else if (check_min_max_int(new_argv))
		return (p_err(""), -1);
	else if (check_duplicate(new_argv))
		return (p_err(""), -1);
	else if (new_argc <= 1)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */