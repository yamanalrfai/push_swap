/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tar_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:57:40 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/16 18:16:41 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*find_tar_a_b(t_node *a, t_node *b)
{
	t_node	*tar;

	tar = bigest_info(b);
	while (b)
	{
		if ((b->info < a->info))
			if ((tar->info > a->info || tar->info < b->info))
				tar = b;
		b = b->next;
	}
	return (tar);
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

int	cheek_max(char *str)
{
	char	*max;
	int		i;
	int		j;

	i = 0;
	j = 0;
	max = "2147483647";
	if (f_strlen(str) > f_strlen(max))
		return (1);
	else if (f_strlen(str) < f_strlen(max))
		return (0);
	if (str[i] == '+')
		j = 1;
	while (str[i + j] == '0')
		j++;
	while (max[i] && str[i + j])
	{
		if (str[i + j] == max[i])
			i++;
		else if (str[i + j] > max[i])
			return (1);
		else
			break ;
	}
	return (0);
}
