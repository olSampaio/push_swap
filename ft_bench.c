/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:42:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/30 19:24:34 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static char	*algorithm_name(int disorder, int algorithm_choice,
	t_stack *list_a)
{
	int	size;

	size = ft_lstsize(list_a);
	if (size == 2)
		return ("Two elements / O(1)");
	else if (size == 3)
		return ("Three elements / O(1)");
	else if (size == 5)
		return ("Five elements / O(1)");
	if (algorithm_choice == 1)
		return ("Simple O(n²)");
	if (algorithm_choice == 2)
		return ("Medium O(n√n)");
	if (algorithm_choice == 3)
		return ("Complex O(n log n)");
	else
	{
		if (disorder < 20)
			return ("Adaptive O(n²)");
		if (disorder <= 50)
			return ("Adaptive O(n√n)");
		return ("Adaptive O(n log n)");
	}
}

void	ft_bench(int algorithm_choice, int disorder, t_operations *ops,
	t_sort_data *data)
{
	int	total_ops;

	if (!ft_issorted(*data->list_a))
		ft_call_algorithm(data);
	total_ops = (ops->pa + ops->pb + ops->rra + ops->rrb + ops->rrr + ops->ra
			+ ops->rb + ops->rr + ops->sa + ops->sb + ops->ss);
	ft_printf(2, "[bench] disorder:	%d.%d%%\n", disorder / 100, disorder % 100);
	ft_printf(2, "[bench] strategy:	%s\n", algorithm_name(disorder,
			algorithm_choice, *data->list_a));
	ft_printf(2, "[bench] total_ops:	%d\n", total_ops);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ops->sa,
		ops->sb, ops->ss, ops->pa, ops->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d",
		ops->ra, ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}
