/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:59:27 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 18:02:42 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

static void	ft_swap(t_stack **list)
{			
	t_stack *node_b;
	t_stack *node_c;
	
	if (!*list || !((*list) -> next))
		return ;		
	node_b = (*list) -> next; 								// a variável node_b recebe B	
	node_b -> prev = NULL; 										// como o B vai se tornar a cabeça da lista, ou seja, o primeiro nó, o prévio, que antes era A, será NULL
	if (node_b -> next) 										// verifica se existe um terceiro nó na lista
	{
		node_c = node_b -> next;								// a variável node_c será o next de B, que até então é o nó C
		node_c -> prev = (*list);								// o nó prévio ao C será o A
		(*list) -> next = node_c; 							// o next da cabeça da lista (nó A) vai apontar para o next do next dela (B -> next == C), apontando para C
	}
	else
		(*list) -> next = NULL;								// caso não tenha um terceiro nó na lista, o next do nó A deve ser NULL
	(*list) -> prev = node_b; 								// O elemento prévio da cabeça da lista (nó A) será o B
	node_b -> next = (*list); 								// B irá apontar para A	como próximo
	(*list) = node_b; 										// B irá se tornar a cabeça da lista	
}

void	sa(t_stack **list_a, t_operations *ops)
{
	ft_swap(list_a);	
	ops->sa++;
	ft_printf("sa/n");
}

void	sb(t_stack **list_b, t_operations *ops)
{	
	ft_swap(list_b);
	ops->sb++;
	ft_printf("sb/n");
}

void	ss(t_stack **list_a, t_stack **list_b, t_operations *ops)
{
	ft_swap(list_a);
	ft_swap(list_b);
	ops->sa++;
	ops->sb++;
	ft_printf("ss/n");
}