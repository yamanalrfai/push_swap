/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:45:35 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/07 18:47:53 by yalrfai          ###   ########.fr       */
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
	if (size > 3)
	{
		push(s_a, s_b, "pb\n");
		push(s_a, s_b, "pb\n");
		size -= 2;
	}
	while (size-- > 3)
	{
		tmp->the_cost = -1;
		sort_a_b(s_a, s_b, tmp);
		tmp_doit(s_a, s_b, tmp);
		push(s_a, s_b, "pb\n");
	}
	cheek_num(s_a);
	size = size_node(*s_b);
	while (size-- != 0)
	{
		tmp->the_cost = -1;
		sort_b_a(s_a, s_b, tmp);
		tmp_doit(s_a, s_b, tmp);
		push(s_b, s_a, "pa\n");
	}
	make_it_okay(s_a);
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
	sort_algo(&stack_a, &stack_b, tmp, size_node(stack_a));
	ft_fre(&stack_a, &stack_b, tmp);
	return (0);
}
/*➜  push_swap ./a.out -4127 1 -396 3700 -107 -2882 -844 -2967 1463 
-4199 -2947 -3699 -3041 -2996 4699 1555 -3614 -1454 -3831 -180 -1319
-1278 -3345 3655 -3804 -3168 325 1932 3257 -2732 1433 1534 476 1494
1641 -4311 1887 3233 -1072 4143 -199 -4505 3314 809 -2770 4937 2213
-138 1259 2872 1770 333 3122 2031 4370 4241 19 -3368 3725 -247
-2145 3525 -3360 -615 3584 2664 -419 -2682 3945 4886 442 2123
-4825 -238 -2028 2092 -2754 2057 1163 1916 -4545 -4623 916 -1865 -2217 -3585
2072 -769 -3213 -2734 1351 793 -1342 2663 -1562 -3503 3610 3805 395 469 */
