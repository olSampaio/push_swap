/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:11:54 by armarque          #+#    #+#             */
/*   Updated: 2026/07/21 16:15:05 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_radix_sort(t_stack *list_a, t_stack *list_b)
{
	int	num_bits;
	int	bits;
	int	i;
	int	pbquantity;
	int	opquantity;

	opquantity = 0;
	num_bits = 0;
	bits = count_bits(get_max(list_a));
	while (num_bits != bits)
	{
		i = 0;
		pbquantity = (dopbra(list_a, list_b, num_bits));
		while (i < pbquantity)
		{
			pa(list_a, list_b);
			// adcionar o contador pro pa
			i++;
		}
		opquantity += pbquantity;
		num_bits++;
	}
}

int	dopbra(t_stack *list_a, t_stack *list_b, int num_bits)
{
	int	i;
	int	lstsize;
	int	pbquantity;

	pbquantity = 0;
	i = 0;
	lstsize = ft_lstsize(list_a);
	while (lstsize > i)
	{
		if ((list_a->index >> num_bits) & 1)
		{
			pb(list_a, list_b);
			// adcionar o contador pro pb
			pbquantity++;
		}
		else
		{
			ra(list_a);
			// adcionar o contador pro ra
		}
		i++;
	}
	return (pbquantity);
}
