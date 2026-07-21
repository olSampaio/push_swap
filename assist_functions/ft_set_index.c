/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:07:15 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 12:47:01 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_index(t_stack *list)
{
	t_stack *node;

	node = list;
	while(node)
	{
		node -> index = ft_search_index(list, node -> value);
		node = node -> next;
	}
}