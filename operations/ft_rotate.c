/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:58:32 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:53:43 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_rotate(t_stack **list)
{
	t_stack	*node_b;
	t_stack	*last;

	if (!*list)
		return ;
	last = ft_lstlast(*list);
	if ((*list)->next)
		node_b = (*list)->next;
	else
		return ;
	(*list)->next = NULL;
	(*list)->prev = last;
	last->next = (*list);
	(*list) = node_b;
	(*list)->prev = NULL;
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
