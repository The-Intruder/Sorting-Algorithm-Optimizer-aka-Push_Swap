/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */

void	link_stack_nodes(t_node *current, t_node *prv, t_node *nxt)
{

}

/* -------------------------------------------------------------------------- */

t_stack	*init_stack_node(char *asci_nbr)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr -> perv = NULL;
	ptr -> indx = 0;
	ptr -> nmbr = ft_atoi(asci_nbr);
	ptr -> next = NULL;
	return (ptr);
}

/* -------------------------------------------------------------------------- */

t_stack	*init_stack(int argc, char **argv)
{
	int		i;
	t_node	*stack_node;

	i = 0;
	while (argc--)
	{
		if (!is_all_digit(argv[i]))
			return (NULL);
		stack_node = init_stack_node(argv[i]);
		if (i == argc - 1)
			link_stack_nodes(stack_node, prv, nxt)
	}
}

/* -------------------------------------------------------------------------- */
"errt %k sryrw"