/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearest_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:31:12 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 21:31:24 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	ft_nearest_top(t_stack *list, t_stack *node, int size)
{
	int pos;

	pos = 0;
	while (list != node)
	{
		pos++;
		list = list->next;
	}
	if (pos <= size / 2)
		return (1);
	return (0);
}