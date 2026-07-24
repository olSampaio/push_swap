/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:31:30 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:18:59 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*ft_get_smaller(t_stack **list_a)
{
	t_stack	*smaller;
	t_stack	*node;

	node = *list_a;
	smaller = node;
	while (node)
	{
		if (smaller->value > node->value)
			smaller = node;
		node = node->next;
	}
	return (smaller);
}

void	ft_selection_sort(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	int		size;
	t_stack	*smaller;

	size = ft_lstsize(*list_a);
	while (*list_a)
	{
		smaller = ft_get_smaller(list_a);
		if (ft_nearest_end(smaller, size) == 1)
		{
			while (*list_a != smaller)
				ra(list_a, ops, use_bench);
			pb(list_a, list_b, ops, use_bench);
		}
		else
		{
			while (*list_a != smaller)
				rra(list_a, ops, use_bench);
			pb(list_a, list_b, ops, use_bench);
		}
		size--;
	}
	while (*list_b)
		pa(list_a, list_b, ops, use_bench);
}
