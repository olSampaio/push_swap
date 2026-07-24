/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrepeated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:59:15 by armarque          #+#    #+#             */
/*   Updated: 2026/07/24 10:08:19 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	ft_is_repeated(t_sort_data *data)
{
	t_stack	*primary_value;
	t_stack	*secundary_value;

	primary_value = *data->list_a;
	while (primary_value)
	{
		secundary_value = primary_value->next;
		while (secundary_value)
		{
			if (secundary_value->value == primary_value->value)
				return (1);
			secundary_value = secundary_value->next;
		}
		primary_value = primary_value->next;
	}
	return (0);
}
