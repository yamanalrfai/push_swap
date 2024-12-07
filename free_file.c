/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:18 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/07 18:20:07 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_all_nodes(t_node **lst)
{
	t_node	*current;
	t_node	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_fr(char **ans)
{
	int	i;

	i = 0;
	if (!ans)
		return ;
	while (ans[i])
	{
		free(ans[i]);
		i++;
	}
	free(ans[i]);
	free(ans);
}

void	ft_fre(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp)
{
	clear_all_nodes(stack_a);
	clear_all_nodes(stack_b);
	free(tmp);
}
