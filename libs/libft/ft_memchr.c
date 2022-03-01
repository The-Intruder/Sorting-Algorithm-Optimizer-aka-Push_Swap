/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:34:57 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/03 21:21:21 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*my_s;
	unsigned char	my_c;

	i = 0;
	my_s = (unsigned char *) s;
	my_c = (unsigned char) c;
	while (i < n)
	{
		if (my_s[i] == my_c)
			return ((void *)&my_s[i]);
		i++;
	}
	return (0);
}
