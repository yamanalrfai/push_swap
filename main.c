/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:45:35 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/07 21:11:44 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsestr(int size, char **argv)
{
	char	*joined;
	char	**split;

	joined = f_strjoin(size, argv, " ");
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined);
	if (!split)
		return (NULL);
	return (split);
}

void	sort_algo(t_node **s_a, t_node **s_b, t_cheepest_move *tmp, int size)
{
	if (size > 2)
	{
		push(s_a, s_b, "pb\n");
		push(s_a, s_b, "pb\n");
		size -= 2;
	}
	if (size == 3)
		sort_three (s_a);
	else
	{
		while (size-- > 2)
		{
			tmp->the_cost = -1;
			sort_a_b(s_a, s_b, tmp);
			tmp_doit(s_a, s_b, tmp);
			push(s_a, s_b, "pb\n");
		}
	}
	while (size_node(*s_b) != 0)
	{
		tmp->the_cost = -1;
		sort_b_a(s_a, s_b, tmp);
		tmp_doit(s_a, s_b, tmp);
		push(s_b, s_a, "pa\n");
	}
}

void	make_it_okay(t_node **stack_a)
{
	t_node	*tmp;

	tmp = smallest_info(*stack_a);
	if (find_node(stack_a, tmp->info) < size_node(*stack_a) / 2)
	{
		while (tmp->info != (*stack_a)->info)
			rotate(stack_a, "ra\n");
	}
	else
	{
		while (tmp->info != (*stack_a)->info)
			rrotate(stack_a, "rra\n");
	}
}

static t_cheepest_move	*tmp_mall(void)
{
	t_cheepest_move	*tmp;

	tmp = malloc(sizeof(t_cheepest_move));
	if (!tmp)
		return (NULL);
	tmp->a = NULL;
	tmp->b = NULL;
	tmp->co_a = 0;
	tmp->co_b = 0;
	tmp->the_cost = -1;
	return (tmp);
}

int	main(int c, char **v)
{
	t_node			*stack_a;
	t_node			*stack_b;
	t_cheepest_move	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (c == 1)
		return (1);
	tmp = tmp_mall();
	if (!tmp || see_c_v(c, v, &stack_a))
	{
		ft_putstr_fd("Error\n", 1);
		free(tmp);
		return (1);
	}
	if (is_sorted(stack_a))
	{
		sort_algo(&stack_a, &stack_b, tmp, size_node(stack_a));
		make_it_okay(&stack_a);
	}
	ft_fre(&stack_a, &stack_b, tmp);
	return (0);
}
