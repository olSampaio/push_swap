/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:42:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:06:43 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	ft_bench(char *algorithm_name, int disorder, t_operations *ops)
{
	int total_ops;

	total_ops = (ops->sa + ops->pb + ops->rra + ops->rrb + ops->rrr + ops->ra
			+ ops->rb + ops->rr + ops->sa + ops->sb + ops->ss + ops->pa);
	ft_printf(2, "[bench] disorder:	%d.%d%%\n", disorder / 100, disorder % 100);	
	ft_printf(2, "[bench] strategy:	%s\n", algorithm_name);
	ft_printf(2, "[bench] total_ops:	%d\n", total_ops);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ops->sa, ops->sb,
		ops->ss, ops->pa, ops->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d", ops->ra,
		ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}