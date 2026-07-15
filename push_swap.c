/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/15 19:36:14 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_index(t_stack *list, int node_value)
{
	int	index;

	index = 0;
	
	while(list)
	{
		if(list -> value < node_value)
			index++;
		list = list -> next;
	}
	return (index);
}

void	ft_set_index(t_stack **list)
{
	t_stack *node;

	node = *list;
	while(node)
	{
		node -> index = ft_search_index(*list, node -> value);
		node = node -> next;
	}
}

int	main(int argc, char **argv)
{
	
}