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

static int	is_all_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && argv[i][j] != '+' && \
				(argv[i][j] < '0' || argv[i][j] > '9') && \
				!ft_isspace(argv[i][j]))
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	check_min_max_int(int argc, char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (-1);
		++i;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

void	p_err(char *err_msg)
{
	write(2, RED, 16);
	write(2, "\nERROR:\t", 8);
	write(2, BLD, 11);
	write(2, "(", 1);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, ")\n\n", 3);
}

/* -------------------------------------------------------------------------- */

int	handle_err(int argc, char **argv)
{
	if (is_all_digit(argc, argv))
		return (p_err("Input Error, found a Non-Digit character"), -1);
	else if (check_duplicate(argc, argv))
		return (p_err("Input Error, found Duplicates"), -1);
	else if (check_min_max_int(argc, argv))
		return (p_err("Input Error, found a Number > or < than INT"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */