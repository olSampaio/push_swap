/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:55:42 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/07 18:13:31 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate(t_stack **list)
{
	t_stack *penultimate;
	t_stack *last;
	
	if (!*list)											// Caso a lista esteja vazia, retorne sem fazer nada.
		return ;									
	last = ft_lstlast(list);							// Guardei o último elemento da lista na varável last
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

void	rrr(t_stack **list_a, t_stack **list_b)
{
	rrb(list_a);
	rra(list_b);
}