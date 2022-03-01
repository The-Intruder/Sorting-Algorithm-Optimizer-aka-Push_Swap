/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:37:25 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/03 21:43:56 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	my_c;

	i = ft_strlen(s);
	my_c = (char) c;
	while (i >= 0)
	{
		if (s[i] == my_c)
			return ((char *)&s[i]);
		else if (i == 0)
			break ;
		i--;
	}
	return (0);
}
