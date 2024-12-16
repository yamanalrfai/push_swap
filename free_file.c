/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:18 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/16 18:02:20 by yalrfai          ###   ########.fr       */
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

int	is_sorted(t_node *head)
{
	t_node	*current;

	if (!head || !head->next)
		return (0);
	current = head;
	while (current->next != NULL)
	{
		if (current->info > current->next->info)
			return (1);
		current = current->next;
	}
	return (0);
}

int	cheek_min(char *str)
{
	char	*min;
	int		i;
	int		j;

	i = 1;
	j = 0;
	min = "2147483648";
	if (str[0] != '-')
		return (0);
	if (f_strlen(str) > f_strlen(min))
		return (1);
	else if (f_strlen(str) < f_strlen(min))
		return (0);
	while (str[i] == '0')
		i++;
	while (min[j] && str[i + j])
	{
		if (str[i + j] == min[j])
			j++;
		else if (str[i + j] > min[j])
			return (1);
		else
			break ;
	}
	return (0);
}
