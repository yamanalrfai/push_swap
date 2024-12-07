/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_comande.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:00:54 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/06 23:17:53 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **st, char *str)
{
	t_node	*sec;

	sec = (*st)->next;
	if (size_node(*st) > 2)
		(*st)->next = sec->next;
	else
		(*st)->next = NULL;
	sec->next = *st;
	*st = sec;
	ft_putstr_fd(str, 1);
}

void	push(t_node **from, t_node **to, char *str)
{
	t_node	*tmp;

	tmp = (*from)->next;
	(*from)->next = NULL;
	node_front(to, *from);
	(*from) = tmp;
	ft_putstr_fd(str, 1);
}

void	rotate(t_node **st, char *str)
{
	t_node	*tmp;
	t_node	*last;

	if (size_node(*st) < 2)
		return ;
	tmp = *st;
	*st = (*st)->next;
	last = last_node(st);
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd(str, 1);
}

void	rrotate(t_node **st, char *str)
{
	t_node	*last;
	t_node	*sec;

	if (size_node(*st) < 2)
		return ;
	last = last_node(st);
	sec = *st;
	while (sec->next != last)
		sec = sec->next;
	sec->next = NULL;
	last->next = *st;
	*st = last;
	ft_putstr_fd(str, 1);
}
