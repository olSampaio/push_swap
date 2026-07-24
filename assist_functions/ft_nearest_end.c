/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearest_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:45:33 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:48:26 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nearest_end(t_stack *node, int size)
{
	int	count_steps;

	count_steps = 0;
	while (node->next)
	{
		count_steps++;
		node = node->next;
	}
	if (count_steps >= size / 2)
		return (1);
	else
		return (2);
}
