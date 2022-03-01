/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_misc_1st.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:07:32 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/12 22:41:39 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (6);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*myptr;

	i = 0;
	myptr = (char *)s;
	while (i++ < n)
		*(myptr++) = 0;
}

/* -------------------------------------------------------------------------- */

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

/* -------------------------------------------------------------------------- */

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	sum;
	char	sign;

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
		sum = (sum * 10) + (str[i++] - '0');
	return (sum * sign);
}

/* -------------------------------------------------------------------------- */

void	ft_putchar(char c, int *outpt_len)
{
	write(1, &c, 1);
	*outpt_len += 1;
}

/* -------------------------------------------------------------------------- */
