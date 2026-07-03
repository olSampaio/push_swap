/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:38:29 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/03 18:02:28 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

void	sa(t_stack_a *list_a);
void	sb(t_stack_b *list_b);
void	ss(t_stack_a *list_a, t_stack_b *list_b);
void	pa(t_stack_a *list_a);
void	pb(t_stack_b *list_b);
void	ra(t_stack_a *list_a);
void	ra(t_stack_a *list_a);
void	rr(t_stack_a *list_a, t_stack_b *list_b);
void	rra(t_stack_a *list_a);
void	rrb(t_stack_b *list_b);
void	rrr(t_stack_a *list_a, t_stack_b *list_b);

typedef struct s_stack_a
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack_a;

typedef struct s_stack_b
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack_b;

#endif