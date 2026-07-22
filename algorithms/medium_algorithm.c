/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:40:47 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 12:02:25 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_organize_return(t_stack **list_a, t_stack **list_b,
		t_operations *ops)
{
	t_stack	*bigger;
	int		nearest;

	while (*list_b)
	{
		bigger = ft_get_bigger(*list_b);
		nearest = ft_nearest_end(bigger, ft_lstsize(*list_b));
		if (nearest == 1)
			while (*list_b != bigger)
				rb(list_b, ops);
		else
			while (*list_b != bigger)
				rrb(list_b, ops);
		pa(list_a, list_b, ops);
	}
}

static void	ft_bucket_nearest(t_stack *list, int size, int min_index,
		int max_index, int *better_move, t_stack **better_node)
{
	int	best_dist;
	int	dist;
	int	count_steps;

	count_steps = 0;
	best_dist = -1;
	while (list)
	{
		if (list->index >= min_index && list->index <= max_index)
		{
			dist = count_steps;
			// dist recebe a distância até o começo
			if (size - count_steps < dist)
				// se a distância até o final for menor que a distância até o começo,
				// dist recebe a distância até o final
				dist = size - count_steps;
			if (best_dist == -1 || dist < best_dist)
			{
				best_dist = dist;
				*better_node = list;
				*better_move = (count_steps > size - count_steps);
			}
		}
		count_steps++;
		list = list->next;
	}
	ft_printf("bucket [%d,%d] -> ", min_index, max_index);
	if (*better_node)
		ft_printf("achou %d (idx %d)\n", (*better_node)->value,
			(*better_node)->index);
	else
		ft_printf("nao achou\n");
	ft_printf("size=%d bucket=[%d,%d]\n", size, min_index, max_index);
}

static void	ft_process_bucket(t_stack **list_a, t_stack **list_b, int *size,
		int min_index, int max_index, t_operations *ops)
{
	int		bucket_atual_size;
	int		better_move;
	t_stack	*better_node;

	better_node = NULL;
	better_move = 0;
	bucket_atual_size = max_index - min_index;
	while (bucket_atual_size-- >= 0)
	{
		ft_bucket_nearest(*list_a, *size, min_index, max_index, &better_move,
			&better_node);
		ft_move_best(list_a, list_b, better_move, better_node, ops);
		(*size)--;
	}
}

void	ft_bucket_sort(t_stack **list_a, t_stack **list_b, t_operations *ops)
{
	int	size;
	int	qt_buckets;
	int	bucket_size;
	int	max_index;
	int	min_index;

	if (!list_a || !*list_a)
		return ;
	size = ft_lstsize(*list_a);
	qt_buckets = ft_bucket_count(size);
	bucket_size = (size + qt_buckets - 1) / qt_buckets;
	max_index = size - 1;
	while (--qt_buckets >= 0)
	{
		size = ft_lstsize(*list_a);
		min_index = max_index - (bucket_size - 1);
		if (min_index < 0)
			min_index = 0;
		ft_process_bucket(list_a, list_b, &size, min_index, max_index, ops);
		max_index = max_index - bucket_size;
	}
	ft_organize_return(list_a, list_b, ops);
}
