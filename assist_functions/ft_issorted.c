/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:20:11 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 18:28:12 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issorted(t_stack *list_a)
{
	if (!list_a)
		return (-1);
	while(list_a -> next && (list_a -> value) < (list_a -> next -> value))	
		list_a = list_a -> next;
	if (list_a -> next == NULL)
		return (1);
	return (0);
}