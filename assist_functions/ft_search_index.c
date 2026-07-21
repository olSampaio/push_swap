/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:06:27 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 11:06:47 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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