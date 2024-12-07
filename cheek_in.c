/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:53:20 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/07 18:20:45 by yalrfai          ###   ########.fr       */
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

static int	checkdup(char **strs)
{
	int			i;
	int			j;
	long long	*num;

	i = 0;
	while (strs[i])
		i++;
	num = malloc(sizeof(*num) * i);
	i = -1;
	while (strs[++i])
		num[i] = ft_atoi(strs[i]);
	i = -1;
	while (strs[++i])
	{
		if (num[i] > FTINTMAX || num[i] < FTINTMIN)
			return (free(num), 1);
		j = i + 1;
		while (strs[j])
		{
			if (num[i] == num[j])
				return (free(num), 1);
			j++;
		}
	}
	return (free(num), 0);
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
		if (add_node(stack_a, ft_atoi(str[i])) == -1)
		{
			ft_fr(str);
			return (1);
		}
		i++;
	}
	ft_fr(str);
	return (0);
}
