/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:26:11 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 22:28:19 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

void	ft_sort_two(t_stack **list_a, t_operations *ops, int use_bench)
{
	if ((*list_a)->value > (*list_a)->next->value)
		sa(list_a, ops, use_bench);
}

static int	see_case(t_stack **list_a)
{
	if ((*list_a)->index > (*list_a)->next->index)
	{
		if ((*list_a)->index > (*list_a)->next->next->index)
		{
			if ((*list_a)->next->index > (*list_a)->next->next->index)
				return (1);
			else
				return (2);
		}
		else if ((*list_a)->next->next->index > (*list_a)->next->index)
			return (3);
	}
	else if ((*list_a)->next->index > (*list_a)->next->next->index)
	{
		if ((*list_a)->index > (*list_a)->next->next->index)
			return (4);
		else
			return (5);
	}
	else
		return (0);
	return (0);
}

void	ft_sort_three(t_stack **list_a, t_operations *ops, int use_bench)
{
	int	number;

	number = see_case(list_a);
	if (number == 1)
	{
		ra(list_a, ops, use_bench);
		sa(list_a, ops, use_bench);
	}
	else if (number == 2)
		ra(list_a, ops, use_bench);
	else if (number == 3)
		sa(list_a, ops, use_bench);
	else if (number == 4)
		rra(list_a, ops, use_bench);
	else if (number == 5)
	{
		sa(list_a, ops, use_bench);
		ra(list_a, ops, use_bench);
	}
	else if (number == 0)
		return ;
}

t_stack	*ft_get_smaller_index(t_stack **list_a)
{
	t_stack	*smaller;
	t_stack	*node;

	node = *list_a;
	smaller = node;
	while (node)
	{
		if (smaller->index > node->index)
			smaller = node;
		node = node->next;
	}
	return (smaller);
}

void	ft_sort_five(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	t_stack	*smaller;

	while (ft_lstsize(*list_a) > 3)
	{
		smaller = ft_get_smaller_index(list_a);
		if (ft_nearest_top(*list_a, smaller, ft_lstsize(*list_a)))
			while (*list_a != smaller)
				ra(list_a, ops, use_bench);
		else
			while (*list_a != smaller)
				rra(list_a, ops, use_bench);
		pb(list_a, list_b, ops, use_bench);
	}
	ft_sort_three(list_a, ops, use_bench);
	pa(list_a, list_b, ops, use_bench);
	pa(list_a, list_b, ops, use_bench);
}
