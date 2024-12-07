/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_thing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:04:04 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/07 16:30:29 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_in_the_rmp(t_node *a, t_node *b, t_cheepest_move *tmp, int move)
{
	tmp->a = a;
	tmp->b = b;
	tmp->the_cost = move;
}

int	up_or_down(int tmp, t_node **stack_a)
{
	if (tmp > (size_node(*stack_a) / 2))
		return (1);
	else
		return (0);
}

void	doing_thinges_rrr(int a, int b, t_node **stack_a, t_node **stack_b)
{
	while (a != 0 && b != 0)
	{
		rrotate(stack_a, "rrr\n");
		rrotate(stack_b, NULL);
		a--;
		b--;
	}
	while (a != 0)
	{
		rrotate(stack_a, "rra\n");
		a--;
	}
	while (b != 0)
	{
		rrotate(stack_b, "rrb\n");
		b--;
	}
}

void	doing_thinges_rr(int a, int b, t_node **stack_a, t_node **stack_b)
{
	while (a != 0 && b != 0)
	{
		rotate(stack_a, "rr\n");
		rotate(stack_b, NULL);
		a--;
		b--;
	}
	while (a != 0)
	{
		rotate(stack_a, "ra\n");
		a--;
	}
	while (b != 0)
	{
		rotate(stack_b, "rb\n");
		b--;
	}
}

void	tmp_doit(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = find_node(stack_a, tmp->a->info);
	tmp_b = find_node(stack_b, tmp->b->info);
	if (up_or_down(tmp_a, stack_a) == up_or_down(tmp_b, stack_b))
	{
		if (up_or_down(tmp_a, stack_a))
		{
			tmp_a = size_node(*stack_a) - tmp_a;
			tmp_b = size_node(*stack_b) - tmp_b;
			doing_thinges_rrr(tmp_a, tmp_b, stack_a, stack_b);
		}
		else
			doing_thinges_rr(tmp->co_a, tmp->co_b, stack_a, stack_b);
		return ;
	}
	if (up_or_down(tmp_a, stack_a))
		doing_thinges_rrr(size_node(*stack_a) - tmp_a, 0, stack_a, stack_b);
	else
		doing_thinges_rr(tmp->co_a, 0, stack_a, stack_b);
	if (up_or_down(tmp_b, stack_b))
		doing_thinges_rrr(0, size_node(*stack_b) - tmp_b, stack_a, stack_b);
	else
		doing_thinges_rr(0, tmp->co_b, stack_a, stack_b);
}
