/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:07:15 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:56:07 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_index(t_stack *list)
{
	t_stack	*node;

	node = list;
	while (node)
	{
		node->index = ft_search_index(list, node->value);
		node = node->next;
	}
}
