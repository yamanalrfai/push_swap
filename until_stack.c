/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:36 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/06 23:17:35 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int add_node(node **old, int inf)
{
    node *a = malloc(sizeof(node));
    if (!a)
    {
        clear_all_nodes(old);
        return (-1);
    }
    a->info = inf;
    a->next = NULL;
    node_back(old, a);
    return (1);
}
void node_back(node **lst, node *new)
{
    node *i;

    if (new == NULL)
        return ;
    if (*lst == NULL)
        *lst = new;
    else
    {
        i = last_node(lst);
        i->next = new;
    }
}
void node_front(node **lst, node *new)
{
    if (new == NULL)
        return ;
    if (*lst == NULL)
        *lst = new;
    else
    {
        new->next = *lst;
        *lst = new;
    }
}
int find_node(node **lst, int inf)
{
    node *i;
    int index;
    
    i = *lst;
    index = 0;
    while (i != NULL && i->info != inf)
    {
        index++;
        i = i->next;
    }
    return (index);
}
node *last_node(node **lst)
{
    node *i;

    i = *lst;
    if (*lst == NULL)
        return (NULL);
    while (i->next != NULL)
        i = i->next; 
    return (i);
}
void clear_all_nodes(node **lst)
{
    node *current = *lst;
    node *next;

    current = *lst;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *lst = NULL;
}
int size_node(node *lst)
{
    int i;

    i = 0;
    if (lst == NULL)
        return (0);
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}