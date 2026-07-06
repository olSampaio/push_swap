/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:36:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/06 15:36:02 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **list_a, t_stack **list_b)
{	
	t_stack *top_b;
	
	if(!*list_b) // caso B esteja vazio, não faz nada
		return ;
	top_b = *list_b; // guarda o topo do B em um variável
	*list_b = top_b -> next; // define o próximo nó da lista B como a cabeça da lista
	if(*list_b) // se a cabeça da lista B existir, faça com que não tenha nenhum item antes
		(*list_b) -> prev = NULL; 
	ft_lstadd_front(list_a, top_b);	// adiciona o topo da B no topo da A
}

void	pb(t_stack **list_a, t_stack **list_b)
{
	t_stack *top_a;
	
	if(!*list_a) // caso A esteja vazio, não faz nada
		return ;
	top_a = *list_a; // guarda o topo do A em um variável
	*list_a = top_a -> next; // define o próximo nó da lista A como a cabeça da lista
	if(*list_a) // se a cabeça da lista A existir, faça com que não tenha nenhum item antes
		(*list_a) -> prev = NULL; 
	ft_lstadd_front(list_b, top_a);	// adiciona o topo da A no topo da B
}