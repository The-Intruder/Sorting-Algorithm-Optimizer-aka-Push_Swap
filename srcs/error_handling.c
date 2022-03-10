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

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				continue ;
			else if (!ft_isdigit(argv[i][j]))
				return (-1);
		}
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
		if (argv[i][j] == '-')
			++j;
		if (ft_strlen(&argv[i][j]) > 10)
			return (-1);
		nbr = atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (-1);
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static void	p_err(char *err_msg)
{
	write(2, RED"ERROR:\t"BLD, 35);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, NC"\n\n", 9);
}

/* -------------------------------------------------------------------------- */

int	handle_err(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		++i;
	if (argc < 2 || i < 2)
		return (p_err("(Input Error, not enough Arguments)"), -1);
	else if (is_all_valid_digits(argv))
		return (p_err("(Input Error, found an Invalid Argument)"), -1);
	else if (check_min_max_int(argv))
		return (p_err("(Input Error, found an Out-Of-Scope Argument)"), -1);
	else if (check_duplicate(argv))
		return (p_err("(Input Error, found a Duplicated Argument)"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */