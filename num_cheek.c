/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_cheek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:42:33 by yalrfai           #+#    #+#             */
/*   Updated: 2024/12/08 16:44:21 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

int	f_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	if (str[0] == '+' || str[0] == '-')
		length--;
	return (length);
}