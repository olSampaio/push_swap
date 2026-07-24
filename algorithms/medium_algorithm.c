/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:40:47 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:55:47 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_organize_return(t_stack **list_a, t_stack **list_b,
		t_operations *ops, int use_bench)
{
	t_stack	*bigger;
	int		nearest;

	while (*list_b)
	{
		bigger = ft_get_bigger(*list_b);
		nearest = ft_nearest_end(bigger, ft_lstsize(*list_b));
		if (nearest == 1)
			while (*list_b != bigger)
				rb(list_b, ops, use_bench);
		else
			while (*list_b != bigger)
				rrb(list_b, ops, use_bench);
		pa(list_a, list_b, ops, use_bench);
	}
}

static void	ft_bucket_nearest(t_stack *list, int size, t_bucket_range range,
		t_bucket_best *best)
{
	int	best_dist;
	int	dist;
	int	count_steps;

	count_steps = 0;
	best_dist = -1;
	while (list)
	{
		if (list->index >= range.min_index && list->index <= range.max_index)
		{
			dist = count_steps;
			if (size - count_steps < dist)
				dist = size - count_steps;
			if (best_dist == -1 || dist < best_dist)
			{
				best_dist = dist;
				best->better_node = list;
				best->better_move = (count_steps > size - count_steps);
			}
		}
		count_steps++;
		list = list->next;
	}
}

static void	ft_process_bucket(t_sort_data *data, int *size,
		t_bucket_range range)
{
	int				bucket_atual_size;
	t_bucket_best	best;

	bucket_atual_size = range.max_index - range.min_index;
	while (bucket_atual_size-- >= 0)
	{
		ft_bucket_nearest(*data->list_a, *size, range, &best);
		ft_move_best(data, &best);
		(*size)--;
	}
}

static void	ft_bucket_init(t_sort_data *data, t_bucket_range *range,
		int *qt_buckets, int *bucket_size)
{
	int	size;

	size = ft_lstsize(*data->list_a);
	*qt_buckets = ft_bucket_count(size);
	*bucket_size = (size + *qt_buckets - 1) / *qt_buckets;
	range->max_index = size - 1;
}

void	ft_bucket_sort(t_stack **list_a, t_stack **list_b, t_operations *ops,
		int use_bench)
{
	t_sort_data		data;
	t_bucket_range	range;
	int				qt_buckets;
	int				bucket_size;
	int				size;

	if (!list_a || !*list_a)
		return ;
	data.list_a = list_a;
	data.list_b = list_b;
	data.ops = ops;
	data.use_bench = use_bench;
	ft_bucket_init(&data, &range, &qt_buckets, &bucket_size);
	while (--qt_buckets >= 0)
	{
		size = ft_lstsize(*list_a);
		range.min_index = range.max_index - (bucket_size - 1);
		if (range.min_index < 0)
			range.min_index = 0;
		ft_process_bucket(&data, &size, range);
		range.max_index = range.max_index - bucket_size;
	}
	ft_organize_return(list_a, list_b, ops, use_bench);
}
