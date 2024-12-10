/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaman-alrifai <yaman-alrifai@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:35:00 by yaman-alrif       #+#    #+#             */
/*   Updated: 2024/12/10 21:06:32 by yaman-alrif      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int					info;
	struct s_node		*next;
}	t_node;

typedef struct s_cheepest_move
{
	t_node	*a;
	t_node	*b;
	int		co_a;
	int		co_b;
	int		the_cost;
}	t_cheepest_move;

void	swap(t_node **st, char *str);
void	push(t_node **from, t_node **to, char *str);
void	rotate(t_node **st, char *str);
void	rrotate(t_node **st, char *str);
void	sort_a_b(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp);
void	sort_three(t_node **stack_a);
void	sort_b_a(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp);
void	sort_algo(t_node **a, t_node **b, t_cheepest_move *tmp, int size);
void	make_it_okay(t_node **stack_a);
void	ft_fre(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp);
void	sort_two(t_node **stack_a);
void	node_back(t_node **lst, t_node *new);
void	clear_all_nodes(t_node **lst);
void	tmp_doit(t_node **stack_a, t_node **stack_b, t_cheepest_move *tmp);
void	save_in_the_rmp(t_node *a, t_node *b, t_cheepest_move *tmp, int move);
void	ft_fr(char **ans);
void	vind_sort(t_node **stack_a);
int		cheek_num(char *ans);
int		see_c_v(int c, char **v, t_node **stack_a);
int		add_node(t_node **old, char *n);
int		find_node(t_node **lst, int inf);
int		size_node(t_node *lst);
int		co_cost(t_node *a, t_node *b, t_node **stack_a, t_node **stack_b);
int		up_or_down(int tmp, t_node **stack_a);
int		is_sorted(t_node *head);
int		cheek_min(char *str);
int		cheek_max(char *str);
int		f_strlen(const char *str);
int		ft_strcmp(char *str1, char *str2);
t_node	*find_tar_b_a(t_node *a, t_node *b);
t_node	*last_node(t_node **lst);
t_node	*bigest_info(t_node *a);
t_node	*smallest_info(t_node *a);
t_node	*find_tar_a_b(t_node *a, t_node *b);
char	*f_strjoin(int size, char **strs, char *sep);
char	**parsestr(int size, char **strs);

#endif
