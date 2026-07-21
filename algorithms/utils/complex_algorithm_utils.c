/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:57:59 by armarque          #+#    #+#             */
/*   Updated: 2026/07/21 16:26:47 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
