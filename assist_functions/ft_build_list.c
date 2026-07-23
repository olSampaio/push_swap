/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:20:22 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 12:45:40 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_build_list(t_stack **list_a, char **argv, int argc)
{
	int		i;
	t_stack	*new_node;
	int		j;

	i = argc - 1;
	while (i >= 1)
	{
		j = 0;
		if (ft_isnumber(argv[i]) == 1)
		{
			new_node = malloc(sizeof(t_stack));
			new_node->value = atoi(argv[i]);
			new_node->index = 0;
			new_node->next = NULL;
			new_node->prev = NULL;
			ft_lstadd_front(list_a, new_node);
		}		
		i--;
	}
}