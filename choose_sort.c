/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:00:39 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/08 13:24:13 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheek_num(char *nptr)
{
	long int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!nptr[i])
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	if (!nptr[i])
		return (1);
	return (0);
}

void	sort_two(t_node **stack_a)
{
	t_node	*a;
	t_node	*b;

	a = *stack_a;
	b = a->next;
	if (a->info > b->info)
		swap(stack_a, "sa\n");
}

void	sort_three(t_node **stack_a)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *stack_a;
	b = a->next;
	c = b->next;
	if (a->info > b->info && b->info < c->info && a->info < c->info)
		swap(stack_a, "sa\n");
	else if (a->info > b->info && b->info > c->info && a->info > c->info)
	{
		swap(stack_a, "sa\n");
		rrotate(stack_a, "rra\n");
	}
	else if (a->info > b->info && b->info < c->info && a->info > c->info)
		rotate(stack_a, "ra\n");
	else if (a->info < b->info && b->info > c->info && a->info < c->info)
	{
		swap(stack_a, "sa\n");
		rotate(stack_a, "ra\n");
	}
	else if (a->info < b->info && b->info > c->info && a->info > c->info)
		rrotate(stack_a, "rra\n");
}
