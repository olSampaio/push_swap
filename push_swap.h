/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:38:29 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 15:40:21 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DECLARAÇÃO DO STRUCT

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// FUNÇÕES DE OPERAÇÕES PUSH_SWAP

void				sa(t_stack **list_a);
void				sb(t_stack **list_b);
void				ss(t_stack **list_a, t_stack **list_b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **list_a);
void				rb(t_stack **list_b);
void				rr(t_stack **list_a, t_stack **list_b);
void				rra(t_stack **list_a);
void				rrb(t_stack **list_b);
void				rrr(t_stack **list_a, t_stack **list_b);

// FUNÇÕES AUXILIARES

void				ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);
int					ft_nearest_end(t_stack *node, int size);

// ALGORITMOS

void				ft_selection_sort(t_stack **list_a, t_stack **list_b);
void				ft_bucket_sort(t_stack **list_a, t_stack **list_b);

// ALGORITMOS - UTILS

t_stack				*ft_get_bigger(t_stack **list_b);
void				ft_move_best(t_stack **list_a, t_stack **list_b,
						int better_move, t_stack *better_node);
int					ft_bucket_count(int size);
int					count_bits(int max);
int					get_max(t_stack *list_a);

#endif