/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:38:29 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/06 12:40:48 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// FUNÇÕES DE OPERAÇÕES PUSH_SWAP

void	sa(t_stack *list);
void	sb(t_stack *list);
void	ss(t_stack *list);
void	pa(t_stack **list_a, t_stack **list_b);
void	pb(t_stack **list_a, t_stack **list_b);
void	ra(t_stack *list);
void	ra(t_stack *list);
void	rr(t_stack *list);
void	rra(t_stack *list);
void	rrb(t_stack *list);
void	rrr(t_stack *list);

// FUNÇÕES AUXILIARES

void	ft_lstadd_front(t_stack **lst, t_stack *new);

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

#endif