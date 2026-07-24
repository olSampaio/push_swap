/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:55:42 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:12:34 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

static void	ft_reverse_rotate(t_stack **list)
{
	t_stack *penultimate;
	t_stack *last;
	
	if (!*list)											// Caso a lista esteja vazia, retorne sem fazer nada.
		return ;									
	last = ft_lstlast(*list);							// Guardei o último elemento da lista na varável last
	if (last -> prev)
		penultimate = last -> prev;						// Caso haja outro elemento antes do último, ele será guardado na var penultimate
	else
		return ;										// Caso não haja, saia sem fazer nada
	last -> next = (*list);								// O last -> next será (*list), pois ele se tornará o primeiro elemento, indo pro começo da lista
	last -> prev = NULL;								// O (*list) -> prev será NULL, pois ele agora é o primeiro elemento da lista, e se tornará a cabeça
	(*list) -> prev = last;								// O (*list) -> prev será o last, pois o antigo último elemento será agora o primeiro, antes do (*list)
	(*list) = last;										// A cabeça da lista (primeiro elemento) se tornará last, que era o último
	penultimate -> next = NULL;							// O penultimate -> next será NULL, pois antepenúltimo elemento agora se tornou o último
}

void	rra(t_stack **list_a, t_operations *ops, int use_bench)
{
	ft_reverse_rotate(list_a);	
	ops->rra++;
	if (use_bench == 0)
		ft_printf(1, "rra\n");
}

void	rrb(t_stack **list_b, t_operations *ops, int use_bench)
{	
	ft_reverse_rotate(list_b);
	ops->rrb++;
	if (use_bench == 0)
		ft_printf(1, "rrb\n");
}

void	rrr(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	ft_reverse_rotate(list_a);
	ft_reverse_rotate(list_b);
	ops->rrr++;
	if (use_bench == 0)
		ft_printf(1, "rrr\n");
}