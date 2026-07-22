/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:36:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 17:24:38 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*top_src;

	if (!src || !*src) // caso o SRC esteja vazio, não faz nada
		return ;
	top_src = *src; // guarda o topo do SRC em um variável
	*src = top_src->next;
	// define o próximo nó da lista SRC como a cabeça da lista
	if (*src) // se a cabeça da lista SRC existir,
		// faça com que não tenha nenhum item antes
		(*src)->prev = NULL;
	top_src->next = *dest;
	if (*dest)
		(*dest)->prev = top_src;
	top_src->prev = NULL;
	*dest = top_src;
}

void	pa(t_stack **a, t_stack **b, t_operations *ops)
{
	if (!b || !*b)
		return ;
	ft_push(b, a);
	ops->pa++;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, t_operations *ops)
{
	if (!a || !*a)
		return ;
	ft_push(a, b);
	ops->pb++;
}
