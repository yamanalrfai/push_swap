/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:36 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/08 13:15:51 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_node **old, char *inf)
{
	t_node	*a;

	a = malloc(sizeof(t_node));
	if (!a)
	{
		clear_all_nodes(old);
		return (-1);
	}
	a->info = ft_atoi(inf);
	a->next = NULL;
	node_back(old, a);
	return (1);
}

void	node_back(t_node **lst, t_node *new)
{
	t_node	*i;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		i = last_node(lst);
		i->next = new;
	}
}

int	find_node(t_node **lst, int inf)
{
	t_node	*i;
	int		index;

	i = *lst;
	index = 0;
	while (i != NULL && i->info != inf)
	{
		index++;
		i = i->next;
	}
	return (index);
}

t_node	*last_node(t_node **lst)
{
	t_node	*i;

	i = *lst;
	if (*lst == NULL)
		return (NULL);
	while (i->next != NULL)
		i = i->next;
	return (i);
}

int	size_node(t_node *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
