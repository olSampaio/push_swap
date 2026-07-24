/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:33:47 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 21:57:30 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

void	ft_error(t_stack **list_a)
{
	ft_lstclear(list_a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
