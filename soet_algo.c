/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soet_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:25:36 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/07 15:05:00 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_b(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp)
{
	t_node	*a;
	t_node	*b;

	a = *stack_a;
	while (a)
	{
		b = find_tar_a_b(a, *stack_b);
		if (tmp->the_cost == -1)
		{
			save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
			tmp->co_a = find_node(stack_a, a->info);
			tmp->co_b = find_node(stack_b, b->info);
		}
		else if (co_cost(a, b, stack_a, stack_b) < tmp->the_cost)
		{
			save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
			tmp->co_a = find_node(stack_a, a->info);
			tmp->co_b = find_node(stack_b, b->info);
		}
		a = a->next;
	}
}

int	clac(int tmp_a, int tmp_b, t_node **stack_a, t_node **stack_b)
{
	int	co;

	co = 0;
	if (up_or_down(tmp_a, stack_a))
		co = size_node(*stack_a) - tmp_a;
	else
		co = tmp_a;
	if (up_or_down(tmp_b, stack_b))
		co += size_node(*stack_b) - tmp_b;
	else
		co += tmp_b;
	return (co);
}

int	co_cost(t_node *a, t_node *b, t_node **stack_a, t_node **stack_b)
{
	int	co;
	int	tmp_a;
	int	tmp_b;

	tmp_a = find_node(stack_a, a->info);
	tmp_b = find_node(stack_b, b->info);
	if (up_or_down(tmp_a, stack_a) == up_or_down(tmp_b, stack_b))
		if (up_or_down(tmp_a, stack_a))
			if ((size_node(*stack_a) - tmp_a) > (size_node(*stack_b) - tmp_b))
				co = (size_node(*stack_a) - tmp_a);
	else
		co = (size_node(*stack_b) - tmp_b);
	else
		if (tmp_a > tmp_b)
			co = tmp_a;
	else
		co = tmp_b;
	else
		co = clac(tmp_a, tmp_b, stack_a, stack_b);
	return (co);
}

void	sort_b_a(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp)
{
	t_node	*a;
	t_node	*b;

	b = *stack_b;
	while (b)
	{
		a = find_tar_b_a(*stack_a, b);
		if (tmp->the_cost == -1)
		{
			save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
			tmp->co_a = find_node(stack_a, a->info);
			tmp->co_b = find_node(stack_b, b->info);
		}
		else if (co_cost(a, b, stack_a, stack_b) < tmp->the_cost)
		{
			save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
			tmp->co_a = find_node(stack_a, a->info);
			tmp->co_b = find_node(stack_b, b->info);
		}
		b = b->next;
	}
}
