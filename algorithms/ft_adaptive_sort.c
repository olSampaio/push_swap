/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 23:15:58 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 23:44:31 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

char	*ft_adaptive_sort(t_sort_data *data)
{
	if (data->disorder < 20)
		return (ft_selection_sort(data->list_a, data->list_b, data->ops,
				data->use_bench), "Adaptive O(n²)");
	if (data->disorder <= 50)
		return (ft_bucket_sort(data->list_a, data->list_b, data->ops,
				data->use_bench), "Adaptive O(n√n)");
	return (ft_radix_sort(data->list_a, data->list_b, data->ops,
			data->use_bench), "Adaptive O(n log n)");
}
