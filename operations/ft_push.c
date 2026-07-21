/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:36:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 18:13:28 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*top_src;

	if (!*src) // caso o SRC esteja vazio, não faz nada
		return ;
	top_src = *src; // guarda o topo do SRC em um variável
	*src = top_src->next;
	// define o próximo nó da lista SRC como a cabeça da lista
	if (*src) // se a cabeça da lista SRC existir,
		// faça com que não tenha nenhum item antes
		(*src)->prev = NULL;
	ft_lstadd_front(dest, top_src); // adiciona o topo da SRC no topo da DEST
}

void	pa(t_stack **a, t_stack **b, t_operations *ops)
{
	ft_push(b, a);
	ops->pa++;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, t_operations *ops)
{
	ft_push(a, b);
	ops->pb++;
	ft_printf("pb\n");
}
