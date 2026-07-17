/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:40:47 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/17 14:17:12 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_bucket_count(int size)
{
	int	count;

	count = 0;
	while (count * count < size)
		count++;
	return (count);
}

static void	ft_nearest(t_stack *list_a, int size, int min_index, int max_index,
	int *better_move, t_stack *better_node)
{
	int dist_start;
	int dist_end;
	int count_steps;	

	count_steps = 0;
	dist_start = -1;
	dist_end = -1;
	while(list_a)
	{
		if(list_a -> index >= min_index && list_a -> index <= max_index)
		{
			if (dist_start == -1 || count_steps < dist_start)
				dist_start = count_steps;
			if (dist_end == -1 || size - count_steps < dist_end)
			{
				dist_end = size - count_steps;			
				better_node = list_a;
			}
		}
		count_steps++;
		list_a = list_a -> next;
	}
	better_move = 1;
	if(dist_start < dist_end)
		better_move = 0;
}

void	ft_bucket_sort(t_stack **list_a, t_stack **list_b)
{
	int size;
	int qt_buckets;
	int bucket_size;
	int max_index;
	int min_index;
	int better_move; // variável para retornar 0 caso seja melhor ra e 1 caso seja melhor rra
	t_stack *better_node;
	
	size = ft_lstsize(*list_a);
	qt_buckets = ft_bucket_count(size);
	bucket_size = (size + qt_buckets - 1) / qt_buckets;
	max_index = size - 1;
	while(--qt_buckets >= 0)
	{
		min_index = (max_index - (bucket_size - 1));
		if (min_index < 0)
			min_index = 0;
		ft_nearest(*list_a, size, min_index, max_index, &better_move, &better_node);
		max_index = max_index - bucket_size;
	}
}
