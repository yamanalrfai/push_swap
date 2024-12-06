/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:35:00 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/06 23:17:28 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct nod
{
    int info;
    struct nod *next;
} node;


typedef struct cheepest_mov
{
    node *a;
    node *b;
    int co_a;
    int co_b;
    int the_cost;
} cheepest_move;


void swap(node **st, char *str);
void push(node **from ,node **to, char *str);
void rotate(node **st, char *str);
void rrotate(node **st, char *str);
void sort_a_b(node **stack_a ,node **stack_b, cheepest_move *tmp);
void sort_three(node **stack_a);
node *find_tar_b_a(node *a, node *b);
int add_node(node **old, int n);
int find_node(node **lst, int inf);
node *last_node(node **lst);
int size_node(node *lst);
void	node_back(node **lst, node *new);
void clear_all_nodes(node **lst);
void node_front(node **lst, node *new);
void see_tmp_and_do_the_the_thing(node **stack_a, node **stack_b, cheepest_move *tmp);
void save_in_the_rmp(node *a, node *b, cheepest_move *tmp, int move);
int co_cost(node *a, node *b, node **stack_a, node **stack_b);
int up_or_down(int tmp, node **stack_a);
node *bigest_info(node *a);
node *smallest_info(node *a);
node *find_tar_a_b(node *a, node *b);
void sort_b_a(node **stack_a ,node **stack_b, cheepest_move *tmp);
void sort_algo(node **stack_a, node **stack_b, cheepest_move *tmp, int size);
void make_it_okay(node **stack_a);
void see_v_a(int c, char **v, node **stack_a);
void ft_fre(node **stack_a, node **stack_b, cheepest_move *tmp);
void sort_two(node **stack_a);
void cheek_num(node **stack_a);
#endif