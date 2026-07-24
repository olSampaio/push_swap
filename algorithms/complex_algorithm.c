/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:11:54 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 22:18:29 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static int	dopbra(t_stack **list_a, t_stack **list_b, int num_bits,
		t_operations *ops, int use_bench)
{
	int	i;
	int	lstsize;
	int	pbquantity;

	pbquantity = 0;
	i = 0;
	lstsize = ft_lstsize(*list_a);
	while (lstsize > i)
	{
		if (((*list_a)->index >> num_bits) & 1)
			ra(list_a, ops, use_bench);
		else
		{
			pb(list_a, list_b, ops, use_bench);
			pbquantity++;
		}
		i++;
	}
	return (pbquantity);
}

void	ft_radix_sort(t_stack **list_a, t_stack **list_b, t_operations *ops, int use_bench)
{
	int	num_bits;
	int	bits;
	int	i;
	int	pbquantity;

	num_bits = 0;
	bits = count_bits(get_max(*list_a));
	while (num_bits != bits)
	{
		i = 0;
		pbquantity = (dopbra(list_a, list_b, num_bits, ops, use_bench));
		while (i < pbquantity)
		{
			pa(list_a, list_b, ops, use_bench);
			i++;
		}
		num_bits++;
	}
}
