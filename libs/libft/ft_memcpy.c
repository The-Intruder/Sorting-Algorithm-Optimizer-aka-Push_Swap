/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:23:16 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/03 15:28:50 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tc_dst;
	char	*tc_src;

	i = 0;
	tc_dst = (char *) dst;
	tc_src = (char *) src;
	if (!tc_dst && !tc_src)
		return (0);
	while (i < n)
	{
		tc_dst[i] = tc_src[i];
		i++;
	}
	return (dst);
}
