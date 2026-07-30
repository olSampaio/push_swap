/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:20:22 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/30 18:04:04 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_build_list(t_stack **list_a, char **argv, int argc)
{
	int		i;
	t_stack	*new_node;
	int		num;

	i = argc - 1;
	while (i >= 0)
	{
		if (ft_isnumber(argv[i]) == 1)
		{
			num = ft_atoi(argv[i]);
			if (num > 2147483647)
				return (ft_error(list_a));
			new_node = malloc(sizeof(t_stack));
			if (!new_node)
				return (ft_error(list_a));
			new_node->value = num;
			new_node->index = 0;
			new_node->next = NULL;
			new_node->prev = NULL;
			ft_lstadd_front(list_a, new_node);
		}
		else
			return (ft_error(list_a));
		i--;
	}
}
