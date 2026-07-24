/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:59:27 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:54:54 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_swap(t_stack **list)
{
	t_stack	*node_b;
	t_stack	*node_c;

	if (!*list || !((*list)->next))
		return ;
	node_b = (*list)->next;
	node_b->prev = NULL;
	if (node_b->next)
	{
		node_c = node_b->next;
		node_c->prev = (*list);
		(*list)->next = node_c;
	}
	else
		(*list)->next = NULL;
	(*list)->prev = node_b;
	node_b->next = (*list);
	(*list) = node_b;
}

void	sa(t_stack **list_a, t_operations *ops, int use_bench)
{
	ft_swap(list_a);
	ops->sa++;
	if (use_bench == 0)
		ft_printf(1, "sa\n");
}

void	sb(t_stack **list_b, t_operations *ops, int use_bench)
{
	ft_swap(list_b);
	ops->sb++;
	if (use_bench == 0)
		ft_printf(1, "sb\n");
}

void	ss(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	ft_swap(list_a);
	ft_swap(list_b);
	ops->ss++;
	if (use_bench == 0)
		ft_printf(1, "ss\n");
}
