/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:32:01 by armarque          #+#    #+#             */
/*   Updated: 2026/07/22 17:38:04 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "push_swap.h"

void	ft_error(t_stack **list_a)
{
	ft_lstclear(list_a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}