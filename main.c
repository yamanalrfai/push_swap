/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:45:35 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/01 12:30:13 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print(node *stack_a)
{
    node *tmp;

    tmp = stack_a;
    while (tmp)
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void make_it_okay(node **stack_a)
{
    node *tmp;

    tmp = smallest_info(*stack_a);
    if (find_node(stack_a, tmp->info) < size_node(*stack_a) / 2)
    {
        while (tmp->info != (*stack_a)->info)
        {
            rotate(stack_a);
            printf("ra\n");
        }
    }
    else
    {
        while (tmp->info != (*stack_a)->info)
        {
            rrotate(stack_a);
            printf("rra\n");
        }
    }
}
int main(int c, char **v)
{
    node *stack_a;
    node *stack_b;
    cheepest_move *tmp;
    
    tmp = malloc(sizeof(cheepest_move));
    if (!tmp)
        return -1;
    tmp->the_cost = -1;
    stack_a = NULL;
    stack_b = NULL;
    for (int i = 1; i < c; i++)
    {
        if (add_node(&stack_a, atoi(v[i])) == -1)
            return -1;
    }
    // print(stack_a);
    int size = size_node(stack_a);
    if (size > 3)
    {
        push(&stack_a, &stack_b);
        printf("pb\n");
        size--;
        push(&stack_a, &stack_b);
        printf("pb\n");
        size--;
        while (size > 3)
        {
            tmp->the_cost = -1;
            sort_a_b(&stack_a,&stack_b, tmp);
            see_tmp_and_do_the_the_thing(&stack_a, &stack_b, tmp);
            push(&stack_a, &stack_b);
            printf("pb\n");
            size--;
        }
    }
    // print(stack_a);
    sort_three(&stack_a);
    // print(stack_a);
    // print(stack_b);
    while (size_node(stack_b) != 0)
    {
        tmp->the_cost = -1;
        sort_b_a(&stack_a,&stack_b, tmp);
        see_tmp_and_do_the_the_thing(&stack_a, &stack_b, tmp);
        push(&stack_b, &stack_a);
        printf("pa\n");
    }
    make_it_okay(&stack_a);
    // print(stack_a);
    clear_all_nodes(&stack_a);
    clear_all_nodes(&stack_b);
    free(tmp);
}
/*➜  push_swap ./a.out -4127 1 -396 3700 -107 -2882 -844 -2967 1463 -4199 -2947 -3699 -3041 -2996 4699 1555 -3614 -1454 -3831 -180 -1319 -1278 -3345 3655 -3804 -3168 325 1932 3257 -2732 1433 1534 476 1494 1641 -4311 1887 3233 -1072 4143 -199 -4505 3314 809 -2770 4937 2213 -138 1259 2872 1770 333 3122 2031 4370 4241 19 -3368 3725 -247 -2145 3525 -3360 -615 3584 2664 -419 -2682 3945 4886 442 2123 -4825 -238 -2028 2092 -2754 2057 1163 1916 -4545 -4623 916 -1865 -2217 -3585 2072 -769 -3213 -2734 1351 793 -1342 2663 -1562 -3503 3610 3805 395 469 */