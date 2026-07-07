/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:38:29 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/07 12:49:21 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// DECLARAÇÃO DO STRUCT

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

// FUNÇÕES DE OPERAÇÕES PUSH_SWAP

void	ft_swap(t_stack **list);
void	ss(t_stack **list_a, t_stack **list_b);
void	ft_push(t_stack **src, t_stack **dest);
void	ra(t_stack *list);
void	ra(t_stack *list);
void	rr(t_stack *list);
void	rra(t_stack *list);
void	rrb(t_stack *list);
void	rrr(t_stack *list);

// FUNÇÕES AUXILIARES

void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);

#endif