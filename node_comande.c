/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_comande.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:00:54 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/11/25 23:04:07 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(node **st)
{
    node *sec;

    sec = (*st)->next;
    if (size_node(*st) > 2)
        (*st)->next = sec->next;
    else
        (*st)->next = NULL;
    sec->next = *st;
    *st = sec;
}
void push(node **from ,node **to)
{
    node *tmp;

    tmp = (*from)->next;
    (*from)->next = NULL;
    node_front(to, *from);
    (*from) = tmp;
}
void rotate(node **st)
{
    node *tmp;
    node *last;

    if (size_node(*st) < 2)
        return;
    tmp = *st;
    *st = (*st)->next;
    last = last_node(st);
    last->next = tmp;
    tmp->next = NULL;
}
void rrotate(node **st)
{
    node *tmp;
    node *last;
    node *sec;

    if (size_node(*st) < 2)
        return;
    last = last_node(st);
    sec = *st;
    while (sec->next != last)
        sec = sec->next;
    sec->next = NULL;
    last->next = *st;
    *st = last;
}