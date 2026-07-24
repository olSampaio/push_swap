/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:35:05 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:21:38 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_get_bigger(t_stack *list_b)
{
	t_stack	*bigger;
	t_stack	*node;

	node = list_b;
	bigger = node;
	while (node)
	{
		if (node->value > bigger->value)
			bigger = node;
		node = node->next;
	}
	return (bigger);
}

void	ft_move_best(t_stack **list_a, t_stack **list_b, int better_move,
		t_stack *better_node, t_operations *ops, int use_bench)
{
	if (better_move == 0)
	{					
		while (*list_a != better_node)
			ra(list_a, ops, use_bench);
	}
	else
		while (*list_a != better_node)
			rra(list_a, ops, use_bench);
	pb(list_a, list_b, ops, use_bench);
}

int	ft_bucket_count(int size)
{
	int count;

	count = 0;
	while (count * count < size)
		count++;
	return (count);
}