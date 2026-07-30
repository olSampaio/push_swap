/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:59:27 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/30 17:13:36 by lusampai         ###   ########.fr       */
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
	(void)use_bench;
	ft_swap(list_a);
	ops->sa++;
	ft_printf(1, "sa\n");
}

void	sb(t_stack **list_b, t_operations *ops, int use_bench)
{
	(void)use_bench;
	ft_swap(list_b);
	ops->sb++;
	ft_printf(1, "sb\n");
}

void	ss(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	(void)use_bench;
	ft_swap(list_a);
	ft_swap(list_b);
	ops->ss++;
	ft_printf(1, "ss\n");
}
