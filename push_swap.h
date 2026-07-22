/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:38:29 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 18:09:55 by armarque         ###   ########.fr       */
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

// FUNÇÕES DE OPERAÇÕES PUSH_SWAP

void				sa(t_stack **list_a, t_operations *ops);
void				sb(t_stack **list_b, t_operations *ops);
void				ss(t_stack **list_a, t_stack **list_b, t_operations *ops);
void				pa(t_stack **a, t_stack **b, t_operations *ops);
void				pb(t_stack **a, t_stack **b, t_operations *ops);
void				ra(t_stack **list_a, t_operations *ops);
void				rb(t_stack **list_b, t_operations *ops);
void				rr(t_stack **list_a, t_stack **list_b, t_operations *ops);
void				rra(t_stack **list_a, t_operations *ops);
void				rrb(t_stack **list_b, t_operations *ops);
void				rrr(t_stack **list_a, t_stack **list_b, t_operations *ops);

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

// ALGORITMOS

void				ft_selection_sort(t_stack **list_a, t_stack **list_b,
						t_operations *ops);
void				ft_bucket_sort(t_stack **list_a, t_stack **list_b,
						t_operations *ops);
void				ft_radix_sort(t_stack **list_a, t_stack **list_b,
						t_operations *ops);

// ALGORITMOS - UTILS

t_stack				*ft_get_bigger(t_stack *list_b);
void				ft_move_best(t_stack **list_a, t_stack **list_b,
						int better_move, t_stack *better_node,
						t_operations *ops);
int					ft_bucket_count(int size);
int					count_bits(int max);
int					get_max(t_stack *list_a);

#endif