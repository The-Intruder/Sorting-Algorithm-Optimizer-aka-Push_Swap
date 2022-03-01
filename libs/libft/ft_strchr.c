/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:21:54 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/04 12:38:57 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	my_c;

	i = 0;
	my_c = (char) c;
	while (s[i])
	{
		if (s[i] == my_c)
			return ((char *)&s[i]);
		i++;
	}
	if (my_c == 0 && s[i] == my_c)
		return ((char *)&s[i]);
	return (0);
}
