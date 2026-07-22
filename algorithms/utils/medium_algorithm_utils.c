/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:35:05 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 17:16:23 by lusampai         ###   ########.fr       */
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
		t_stack *better_node, t_operations *ops)
{
	if (better_move == 0)
	{
		printf("Topo=%d  Procurando=%d (index=%d)\n", (*list_a)->value,
			better_node->value, better_node->index);
		while (*list_a != better_node)
			ra(list_a, ops);
	}
	else
		while (*list_a != better_node)
			rra(list_a, ops);
	pb(list_a, list_b, ops);
}

int	ft_bucket_count(int size)
{
	int count;

	count = 0;
	while (count * count < size)
		count++;
	return (count);
}