/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:57:59 by armarque          #+#    #+#             */
/*   Updated: 2026/07/21 12:49:36 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// ordenar antes de pegar o maximo, ou seja pegar pelo rank

int	get_max(t_stack *list_a)
{
	int	max;

	max = 0;
	while (list_a)
	{
		if (list_a->index > max)
			max = list_a->index;
		list_a = list_a->next;
	}
	return (max);
}

// 1 10 200 2000 509999

//	0 1 2 3 4

int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while (max != 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

// int	to_binary(int value)
// {
// 	int	binary;
// 	int	mult;

// 	mult = 1;
// 	binary = 0;
// 	while (value != 0)
// 	{
// 		binary += (value % 2) * mult;
// 		mult = mult * 10;
// 		value = value / 2;
// 	}
// 	return (binary);
// }

// int	count_digits(t_stack *list_a)
// {
// 	int	digits;
// 	int	value;

// 	digits = 0;
// 	value = list_a->value;
// 	while (value != 0)
// 	{
// 		digits++;
// 		value = value / 10;
// 	}
// 	return (digits);
// }

int	radix_sort(t_stack *list_a)
{
	int		bits;
	int		num_bits;
	t_stack	*newstack;
	t_stack	*stack0;

	num_bits = 0;
	bits = count_bits(get_max(list_a));
	while (num_bits != bits)
	{
		while ((list_a->index) & 1)
		{
			newstack = list_a;
			newstack = newstack->next;
			num_bits += 1;
			list_a->index >> num_bits;
			list_a = list_a->next;
		}
		while ((list_a->index) & 0)
		{
			stack0 = list_a;
			stack0 = stack0->next;
			num_bits += 1;
			list_a->index >> num_bits;
			list_a = list_a->next;
		}
		newstack = stack0;
	}
}
