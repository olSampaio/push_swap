/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:06:23 by armarque          #+#    #+#             */
/*   Updated: 2026/07/22 19:06:35 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_exit(t_stack **list_a, t_stack **list_b)
{
	ft_lstclear(list_a);
	ft_lstclear(list_b);
	return (0);
}