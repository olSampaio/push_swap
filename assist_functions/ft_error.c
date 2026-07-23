/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:33:47 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 12:36:04 by armarque         ###   ########.fr       */
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

void	ft_bench(char *algorithm_name, int disorder, t_operations *ops)
{
	int total_ops;

	total_ops = (ops->sa + ops->pb + ops->rra + ops->rrb + ops->rrr + ops->ra
			+ ops->rb + ops->rr + ops->sa + ops->sb + ops->ss + ops->pa);
	ft_printf("[bench] disorder:	%d.%d%%\n", disorder / 100, disorder % 100);
	ft_printf("[bench] strategy:	%s\n", algorithm_name);
	ft_printf("[bench] total_ops:	%d\n", total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ops->sa, ops->sb,
		ops->ss, ops->pa, ops->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d", ops->ra,
		ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}