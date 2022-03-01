/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:43:18 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/04 10:19:31 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tc_s1;
	unsigned char	*tc_s2;

	i = 0;
	tc_s1 = (unsigned char *)s1;
	tc_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (tc_s1[i] != tc_s2[i])
			return (tc_s1[i] - tc_s2[i]);
		i++;
	}
	return (0);
}
