/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:29:58 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 17:04:54 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_value_at(t_stack *list_a, int index)
{
	while (index)
	{
		list_a = list_a->next;
		index--;
	}
	return (list_a->value);
}

int	compute_disorder(t_stack *list_a)
{
	float	mistakes;
	float	total_pairs;
	int		result;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < (ft_lstsize(list_a) - 1))
	{
		j = i + 1;
		while (j < (ft_lstsize(list_a)))
		{
			total_pairs += 1;
			if (get_value_at(list_a, i) > get_value_at(list_a, j))
				mistakes += 1;
			j++;
		}
		i++;
	}
	result = (mistakes / total_pairs) * 100.0f + 0.5f;
	return ((int)((mistakes / total_pairs) * 100 + 0.5));
}
