/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:58:32 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:13:01 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

static void	ft_rotate(t_stack **list)
{		
	t_stack *node_b;
	t_stack *last;
	
	if (!*list)											// Caso a lista esteja vazia, retorne sem fazer nada.
		return ;									
	last = ft_lstlast(*list);							// Guardei o último elemento da lista na varável last
	if ((*list) -> next)
		node_b = (*list) -> next;						// Caso haja outro elemento depois do primeiro, ele será guardado na var node_b
	else
		return ;										// Caso não haja, saia sem fazer nada
	(*list) -> next = NULL;								// O (*list) -> next será NULL, pois ele se tornará o último elemento, indo pro final da lista
	(*list) -> prev = last;								// O (*list) -> prev será o last, pois o antigo último elemento será agora o antepenúltimo, antes do (*list)
	last -> next = (*list);								// O last -> next irá ser o (*list), visto que agora ele será o último nó da lista
	(*list) = node_b;									// A cabeça da lista (primeiro elemento) se tornará node_b, que era o segundo
	(*list) -> prev = NULL;								// O node_b -> prev será NULL, pois ele agora é a cabeça da lista
}

void	ra(t_stack **list_a, t_operations *ops, int use_bench)
{
	ft_rotate(list_a);
	ops->ra++;
	if (use_bench == 0)
		ft_printf(1, "ra\n");
}

void	rb(t_stack **list_b, t_operations *ops, int use_bench)
{	
	ft_rotate(list_b);
	ops->rb++;
	if (use_bench == 0)
		ft_printf(1, "rb\n");
}

void	rr(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	ft_rotate(list_a);
	ft_rotate(list_b);
	ops->rr++;
	if (use_bench == 0)
		ft_printf(1, "rr\n");
}