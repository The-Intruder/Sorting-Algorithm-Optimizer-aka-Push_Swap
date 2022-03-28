/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:10:46 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/09 09:39:16 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(count * size);
	if (ptr == NULL)
		return (write(2, RED"ERROR\n"NC, 29), exit(-1), NULL);
	ft_bzero(ptr, count * size);
	return ((void *) ptr);
}
