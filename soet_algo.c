/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soet_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:25:36 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/07 11:59:22 by yaman-alrif      ###   ########.fr       */
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

void	sort_two(t_node **stack_a)
{
	t_node	*a;
	t_node	*b;

	a = *stack_a;
	b = a->next;
	if (a->info > b->info)
		swap(stack_a, "sa\n");
}

void	cheek_num(t_node **stack_a)
{
	if (size_node(*stack_a) == 2)
		sort_two(stack_a);
	else
		sort_three(stack_a);
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

int	up_or_down(int tmp, t_node **stack_a)
{
	if (tmp > (size_node(*stack_a) / 2))
		return (1);
	else
		return (0);
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

void	save_in_the_rmp(t_node *a, t_node *b, t_cheepest_move *tmp, int move)
{
	tmp->a = a;
	tmp->b = b;
	tmp->the_cost = move;
}

t_node	*find_tar_a_b(t_node *a, t_node *b)
{
	t_node	*tar;

	tar = bigest_info(b);
	while (b)
	{
		if ((b->info < a->info))
			if ((tar->info > a->info || tar->info > b->info))
				tar = b;
		b = b->next;
	}
	return (tar);
}

t_node	*bigest_info(t_node *a)
{
	t_node	*big;

	big = a;
	while (a)
	{
		if (big->info < a->info)
			big = a;
		a = a->next;
	}
	return (big);
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

t_node	*find_tar_b_a(t_node *a, t_node *b)
{
	t_node	*tar;

	tar = smallest_info(a);
	while (a)
	{
		if ((a->info > b->info))
			if ((tar->info < b->info || tar->info > a->info))
				tar = a;
		a = a->next;
	}
	return (tar);
}

t_node	*smallest_info(t_node *a)
{
	t_node	*small;

	small = a;
	while (a)
	{
		if (small->info > a->info)
			small = a;
		a = a->next;
	}
	return (small);
}
