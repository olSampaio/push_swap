/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:35:05 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:39:25 by armarque         ###   ########.fr       */
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

void	ft_move_best(t_sort_data *data, t_bucket_best *best)
{
	if (best->better_move == 0)
	{
		while (*data->list_a != best->better_node)
			ra(data->list_a, data->ops, data->use_bench);
	}
	else
		while (*data->list_a != best->better_node)
			rra(data->list_a, data->ops, data->use_bench);
	pb(data->list_a, data->list_b, data->ops, data->use_bench);
}

int	ft_bucket_count(int size)
{
	int	count;

	count = 0;
	while (count * count < size)
		count++;
	return (count);
}
