/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tar_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:57:40 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/07 19:42:46 by yalrfai          ###   ########.fr       */
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
