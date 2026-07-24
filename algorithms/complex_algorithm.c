/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:11:54 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 23:39:45 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static int	dopbra(t_sort_data *data, int num_bits)
{
	int	i;
	int	lstsize;
	int	pbquantity;

	pbquantity = 0;
	i = 0;
	lstsize = ft_lstsize(*data->list_a);
	while (lstsize > i)
	{
		if (((*data->list_a)->index >> num_bits) & 1)
			ra(data->list_a, data->ops, data->use_bench);
		else
		{
			pb(data->list_a, data->list_b, data->ops, data->use_bench);
			pbquantity++;
		}
		i++;
	}
	return (pbquantity);
}

void	ft_radix_sort(t_stack **list_a, t_stack **list_b, t_operations *ops,
		int use_bench)
{
	t_sort_data	data;
	int			num_bits;
	int			bits;
	int			i;
	int			pbquantity;

	data.list_a = list_a;
	data.list_b = list_b;
	data.ops = ops;
	data.use_bench = use_bench;
	num_bits = 0;
	bits = count_bits(get_max(*list_a));
	while (num_bits != bits)
	{
		i = 0;
		pbquantity = (dopbra(&data, num_bits));
		while (i < pbquantity)
		{
			pa(list_a, list_b, ops, use_bench);
			i++;
		}
		num_bits++;
	}
}
