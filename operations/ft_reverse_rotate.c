/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:55:42 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:54:27 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_reverse_rotate(t_stack **list)
{
	t_stack	*penultimate;
	t_stack	*last;

	if (!*list)
		return ;
	last = ft_lstlast(*list);
	if (last->prev)
		penultimate = last->prev;
	else
		return ;
	last->next = (*list);
	last->prev = NULL;
	(*list)->prev = last;
	(*list) = last;
	penultimate->next = NULL;
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

void	rrr(t_stack **list_a, t_stack **list_b, t_operations *ops,
		int use_bench)
{
	ft_reverse_rotate(list_a);
	ft_reverse_rotate(list_b);
	ops->rrr++;
	if (use_bench == 0)
		ft_printf(1, "rrr\n");
}
