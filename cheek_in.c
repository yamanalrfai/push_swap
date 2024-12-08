/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:53:20 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/08 16:43:00 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkinvalid(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		if (cheek_num(strs[i]))
			return (1);
		j = 0;
		while (strs[i][j])
		{
			if (!ft_isdigit(strs[i][j]))
				if (strs[i][j] != '-' && strs[i][j] != '+')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	dup_(char **strs, int i)
{
	int	j;

	j = i + 1;
	while (strs[j])
	{
		if (my_strcmp(strs[j], strs[i]) == 0)
			return (1);
		j++;
	}
	return (0);
}

static int	checkdup(char **strs)
{
	int			i;

	i = -1;
	while (strs[++i])
	{
		if (dup_(strs, i) || cheek_max(strs[i]) || cheek_max(strs[i]))
			return (1);
	}
	return (0);
}

char	*f_strjoin(int size, char **strs, char *sep)
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

int	see_c_v(int c, char **v, t_node **stack_a)
{
	char	**str;
	int		i;

	i = 0;
	str = parsestr(--c, v + 1);
	if (!str || checkinvalid(str) || checkdup(str))
	{
		ft_fr(str);
		return (1);
	}
	while (str[i])
	{
		if (add_node(stack_a, str[i]) == -1)
		{
			ft_fr(str);
			return (1);
		}
		i++;
	}
	ft_fr(str);
	return (0);
}
