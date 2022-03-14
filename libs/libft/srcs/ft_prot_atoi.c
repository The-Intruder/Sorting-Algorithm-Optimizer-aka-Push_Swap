/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:13:46 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/02 16:17:00 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_prot_atoi(const char *str)
{
	int		i;
	long	sum;
	int		sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
	{
		sum = (sum * 10) + (str[i++] - '0');
		if ((sum > 2147483647 && sum < -2147483648))
			return (exit(-1), 0);
	}
	sum *= sign;
	return ((int)sum);
}
