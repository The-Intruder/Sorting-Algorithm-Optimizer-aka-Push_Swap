/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:08:08 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/14 13:06:58 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		ptr = *lst;
		del((*lst)-> content);
		(*lst) = (*lst)-> next;
		free(ptr);
	}
	*lst = NULL;
}
