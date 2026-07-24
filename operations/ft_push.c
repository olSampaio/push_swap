/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:36:51 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:54:40 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*top_src;

	if (!src || !*src)
		return ;
	top_src = *src;
	*src = top_src->next;
	if (*src)
		(*src)->prev = NULL;
	top_src->next = *dest;
	if (*dest)
		(*dest)->prev = top_src;
	top_src->prev = NULL;
	*dest = top_src;
}

void	pa(t_stack **a, t_stack **b, t_operations *ops, int use_bench)
{
	if (!b || !*b)
		return ;
	ft_push(b, a);
	ops->pa++;
	if (use_bench == 0)
		ft_printf(1, "pa\n");
}

void	pb(t_stack **a, t_stack **b, t_operations *ops, int use_bench)
{
	if (!a || !*a)
		return ;
	ft_push(a, b);
	ops->pb++;
	if (use_bench == 0)
		ft_printf(1, "pb\n");
}
