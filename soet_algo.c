/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soet_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:25:36 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/01 12:09:26 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_a_b(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    node *a;
    node *b;

    a = *stack_a;
    while (a)
    {
        b = find_tar_a_b(a, *stack_b);
        if (tmp->the_cost == -1)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        else if (co_cost(a, b, stack_a, stack_b) < tmp->the_cost)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        a = a->next;
    }
}
void sort_three(node **stack_a)
{
    node *a;
    node *b;
    node *c;

    a = *stack_a;
    if (size_node(a) == 1)
        return;
    if (size_node(a) == 2)
    {
        if (a->info > a->next->info)
        {
            swap(stack_a);
            printf("sa\n");
        }
        return;
    }
    b = a->next;
    c = b->next;
    if (a->info > b->info && b->info < c->info && a->info < c->info)
    {
        swap(stack_a);
        printf("sa\n");
    }
    else if (a->info > b->info && b->info > c->info && a->info > c->info)
    {
        swap(stack_a);
        rrotate(stack_a);
        printf("sa\n");
        printf("rra\n");
    }
    else if (a->info > b->info && b->info < c->info && a->info > c->info)
    {
        rotate(stack_a);
        printf("ra\n");
    }
    else if (a->info < b->info && b->info > c->info && a->info < c->info)
    {
        swap(stack_a);
        rotate(stack_a);
        printf("sa\n");
        printf("ra\n");
    }
    else if (a->info < b->info && b->info > c->info && a->info > c->info)
    {
        rrotate(stack_a);
        printf("rra\n");
    }
}
int up_or_down(int tmp, node **stack_a)
{
    if (tmp > size_node(*stack_a) / 2)
        return (1);
    else
        return (0);
}
int co_cost(node *a, node *b, node **stack_a, node **stack_b)
{
    int co;
    int tmp_a;
    int tmp_b;

    tmp_a = find_node(stack_a, a->info);
    tmp_b = find_node(stack_b, b->info);
    if (up_or_down(tmp_a, stack_a) == up_or_down(tmp_b, stack_b))
    {
        if (up_or_down(tmp_a, stack_a))
        {
            if ((size_node(*stack_a) - tmp_a) > (size_node(*stack_b) - tmp_b))
                co = (size_node(*stack_a) - tmp_a);
            else
                co = (size_node(*stack_b) - tmp_b);
        }
        else
        {
            if (tmp_a > tmp_b)
                co = tmp_a;
            else
                co = tmp_b;
        }
        // if (tmp_a > tmp_b)
        // {    
        //     co = tmp_a;
        //     if (up_or_down(tmp_a, stack_a))
        //         co = size_node(*stack_a) - co;
        // }
        // else
        // {
        //     co = tmp_b;
        //     if (up_or_down(tmp_b, stack_b))
        //         co = size_node(*stack_b) - co;
        // }    
        return (co);
    }
    if (up_or_down(tmp_a, stack_a))
        co = size_node(*stack_a) - tmp_a;
    else
        co = tmp_a;
    if (up_or_down(tmp_b, stack_b))
        co += size_node(*stack_b) - tmp_b;
    else
        co += tmp_b;
    return (co);
}
void save_in_the_rmp(node *a, node *b, cheepest_move *tmp, int move)
{
    tmp->a = a;
    tmp->b = b;
    tmp->the_cost = move;
}
node *find_tar_a_b(node *a, node *b)
{
    node *tar;

    tar = bigest_info(b);
    while (b)
    {
        if ((b->info < a->info))
            if ((tar->info > a->info || tar->info > b->info))
                tar = b;
        b = b->next;
    }
    return (tar);
}
node *bigest_info(node *a)
{
    node *big;
    big = a;
    while (a)
    {
        if (big->info < a->info)
            big = a;
        a = a->next;
    }
    return (big);
}
void see_tmp_and_do_the_the_thing(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    int tmp_a;
    int tmp_b;

    tmp_a = find_node(stack_a, tmp->a->info);
    tmp_b = find_node(stack_b, tmp->b->info);
    if (up_or_down(tmp_a, stack_a) == up_or_down(tmp_b, stack_b))
    {
        if (up_or_down(tmp_a, stack_a))
        {
            tmp->co_a = size_node(*stack_a) - tmp_a;
            tmp->co_b = size_node(*stack_b) - tmp_b;
            while (tmp->co_a != 0 && tmp->co_b != 0)
            {
                rrotate(stack_a);
                rrotate(stack_b);
                tmp->co_a--;
                tmp->co_b--;
                printf("rrr\n");
            }
            while (tmp->co_a != 0)
            {
                rrotate(stack_a);
                tmp->co_a--;
                printf("rra\n");
            }
            while (tmp->co_b != 0)
            {
                rrotate(stack_b);
                tmp->co_b--;
                printf("rrb\n");
            }
        }
        else
        {
            while (tmp->co_a != 0 && tmp->co_b != 0)
            {
                rotate(stack_a);
                rotate(stack_b);
                tmp->co_a--;
                tmp->co_b--;
                printf("rr\n");
            }
            while (tmp->co_a != 0)
            {
                rotate(stack_a);
                tmp->co_a--;
                printf("ra\n");
            }
            while (tmp->co_b != 0)
            {
                rotate(stack_b);
                tmp->co_b--;
                printf("rb\n");
            }
        }
    }
    else
    {
        if (up_or_down(tmp_a, stack_a))
        {
            tmp->co_a = size_node(*stack_a) - tmp_a;
            while (tmp->co_a != 0)
            {
                rrotate(stack_a);
                tmp->co_a--;
                printf("rra\n");
            }
        }
        else
        {
            while (tmp->co_a != 0)
            {
                rotate(stack_a);
                tmp->co_a--;
                printf("ra\n");
            }
        }
        if (up_or_down(tmp_b, stack_b))
        {
            tmp->co_b = size_node(*stack_b) - tmp_b;
            while (tmp->co_b != 0)
            {
                rrotate(stack_b);
                tmp->co_b--;
                printf("rrb\n");
            }
        }
        else
        {
            while (tmp->co_b != 0)
            {
                rotate(stack_b);
                tmp->co_b--;
                printf("rb\n");
            }
        }
    }
}
void sort_b_a(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    node *a;
    node *b;

    b = *stack_b;
    while (b)
    {
        a = find_tar_b_a(*stack_a, b);
        if (tmp->the_cost == -1)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        else if (co_cost(a, b, stack_a, stack_b) < tmp->the_cost)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        b = b->next;
    }
}
node *find_tar_b_a(node *a, node *b)
{
    node *tar;

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
node *smallest_info(node *a)
{
    node *small;
    small = a;
    while (a)
    {
        if (small->info > a->info)
            small = a;
        a = a->next;
    }
    return (small);
}
