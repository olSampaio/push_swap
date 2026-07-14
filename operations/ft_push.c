/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:36:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/14 14:24:58 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{	
	t_stack *top_src;
	
	if(!*src) // caso o SRC esteja vazio, não faz nada
		return ;
	top_src = *src; // guarda o topo do SRC em um variável
	*src = top_src -> next; // define o próximo nó da lista SRC como a cabeça da lista
	if(*src) // se a cabeça da lista SRC existir, faça com que não tenha nenhum item antes
		(*src) -> prev = NULL; 
	ft_lstadd_front(dest, top_src);	// adiciona o topo da SRC no topo da DEST
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
}
