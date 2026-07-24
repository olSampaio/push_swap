/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:38:29 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:28:06 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DECLARAÇÃO DE STRUCTS

typedef struct s_operations
{
	int				pa;
	int				pb;
	int				rra;
	int				rrb;
	int				rrr;
	int				ra;
	int				rb;
	int				rr;
	int				sa;
	int				sb;
	int				ss;
}					t_operations;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					compute_disorder(t_stack *list_a);
void				ft_bench(char *algorithm_name, int disorder,
						t_operations *ops);

// FUNÇÕES DE OPERAÇÕES PUSH_SWAP

void				sa(t_stack **list_a, t_operations *ops, int use_bench);
void				sb(t_stack **list_b, t_operations *ops, int use_bench);
void				ss(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench);
void				pa(t_stack **a, t_stack **b, t_operations *ops, int use_bench);
void				pb(t_stack **a, t_stack **b, t_operations *ops, int use_bench);
void				ra(t_stack **list_a, t_operations *ops, int use_bench);
void				rb(t_stack **list_b, t_operations *ops, int use_bench);
void				rr(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench);
void				rra(t_stack **list_a, t_operations *ops, int use_bench);
void				rrb(t_stack **list_b, t_operations *ops, int use_bench);
void				rrr(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench);

// FUNÇÕES AUXILIARES

void				ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);
int					ft_nearest_end(t_stack *node, int size);
long				ft_atoi(const char *nptr);
int					ft_search_index(t_stack *list, int node_value);
void				ft_set_index(t_stack *list);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_isnumber(char *str);
char				*ft_itoa(int n);
int					ft_is_repeated(t_stack *list_a, int value);
void				ft_lstclear(t_stack **lst);
void				ft_error(t_stack **list_a);
int					ft_issorted(t_stack *list_a);
void				ft_bench(char *algorithm_name, int disorder,
						t_operations *ops);
int					ft_exit(t_stack **list_a, t_stack **list_b);
char				**ft_split(char const *s, char c);
void				ft_fillstruct_ops(t_operations *ops);
char				**ft_prepare_numbers(char **argv, int argc, int offset,
						int *count);
int					see_size(char **argv);
void				ft_putstr_fd(char *s, int fd);
void				ft_build_list(t_stack **list_a, char **argv, int argc);
int					ft_nearest_top(t_stack *list, t_stack *node, int size);

// ALGORITMOS

void				ft_selection_sort(t_stack **list_a, t_stack **list_b,
						t_operations *ops, int use_bench);
void				ft_bucket_sort(t_stack **list_a, t_stack **list_b,
						t_operations *ops, int use_bench);
void				ft_radix_sort(t_stack **list_a, t_stack **list_b,
						t_operations *ops, int use_bench);
void				ft_sort_two(t_stack **list_a, t_operations *ops, int use_bench);

void				ft_sort_three(t_stack **list_a, t_operations *ops, int use_bench);
void				ft_sort_five(t_stack **list_a, t_stack **list_b,
						t_operations *ops, int use_bench);

// ALGORITMOS - UTILS

t_stack				*ft_get_bigger(t_stack *list_b);
void				ft_move_best(t_stack **list_a, t_stack **list_b,
						int better_move, t_stack *better_node,
						t_operations *ops, int use_bench);
int					ft_bucket_count(int size);
int					count_bits(int max);
int					get_max(t_stack *list_a);

#endif