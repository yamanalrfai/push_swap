/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:45:35 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/06 23:28:17 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_algo(node **stack_a, node **stack_b, cheepest_move *tmp, int size)
{
    if (size > 3)
    {
        push(stack_a, stack_b, "pb\n");
        push(stack_a, stack_b, "pb\n");
        size-=2;
    }
    while (size-- > 3)
    {
        tmp->the_cost = -1;
        sort_a_b(stack_a, stack_b, tmp);
        see_tmp_and_do_the_the_thing(stack_a, stack_b, tmp);
        push(stack_a, stack_b, "pb\n");
    }
    cheek_num(stack_a);
    size = size_node(*stack_b);
    while (size-- != 0)
    {
        tmp->the_cost = -1;
        sort_b_a(stack_a, stack_b, tmp);
        see_tmp_and_do_the_the_thing(stack_a, stack_b, tmp);
        push(stack_b, stack_a, "pa\n");
    }
    make_it_okay(stack_a);
}
void make_it_okay(node **stack_a)
{
    node *tmp;

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
static char	*strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	j = ft_getlen(size, strs, sep);
	s = malloc(j + 1);
	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			s[k++] = strs[i][j++];
		if (i++ < size - 1)
		{
			j = 0;
			while (sep[j])
				s[k++] = sep[j++];
		}
	}
    s[k] = 0;
	return (s);
}
static char	**parsestr(int size, char **argv)
{
	char	*joined;
	char	**split;

	joined = strjoin(size, argv, " ");
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined);
	if (!split)
		return (NULL);
	return (split);
}
void	ft_fr(char **ans, size_t i)
{
	while (i != 0)
	{
		free(ans[i]);
		i--;
	}
	free(ans[i]);
}
void see_v_a(int c, char **v, node **stack_a)
{
    char **str;
    int i;
    
    i = 0;
    str = parsestr(--c, v + 1);
    if (!str)
        exit(1);
    while (str[i])
    {
        if (add_node(stack_a, ft_atoi(str[i])) == -1)
            exit(1);
        i++;
    }
    ft_fr(str, i);
    free(str);
}
void ft_fre(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    clear_all_nodes(stack_a);
    clear_all_nodes(stack_b);
    free(tmp);
}
int main(int c, char **v)
{
    node *stack_a;
    node *stack_b;
    cheepest_move *tmp;
    
    stack_a = NULL;
    stack_b = NULL;
    if (c == 1)
        return 0;
    tmp = malloc(sizeof(cheepest_move));
    if (!tmp)
        return -1;
    see_v_a(c, v, &stack_a);
    sort_algo(&stack_a, &stack_b, tmp, size_node(stack_a));     
    ft_fre(&stack_a, &stack_b, tmp);
    return (0);
}
/*➜  push_swap ./a.out -4127 1 -396 3700 -107 -2882 -844 -2967 1463 -4199 -2947 -3699 -3041 -2996 4699 1555 -3614 -1454 -3831 -180 -1319 -1278 -3345 3655 -3804 -3168 325 1932 3257 -2732 1433 1534 476 1494 1641 -4311 1887 3233 -1072 4143 -199 -4505 3314 809 -2770 4937 2213 -138 1259 2872 1770 333 3122 2031 4370 4241 19 -3368 3725 -247 -2145 3525 -3360 -615 3584 2664 -419 -2682 3945 4886 442 2123 -4825 -238 -2028 2092 -2754 2057 1163 1916 -4545 -4623 916 -1865 -2217 -3585 2072 -769 -3213 -2734 1351 793 -1342 2663 -1562 -3503 3610 3805 395 469 */