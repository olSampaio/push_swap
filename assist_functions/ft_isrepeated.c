/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrepeated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:59:15 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 13:49:43 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	ft_is_repeated(t_stack *list_a, int value)
{
	while (list_a)
	{
		if (list_a->value == value)
			return (1);
		list_a = list_a->next;
	}
	return (0);
}
