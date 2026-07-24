/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:51:11 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static int	verify_flags(char **argv, int *use_bench)
{
	int	i;
	int	algorithm;

	algorithm = 0;
	i = 1;
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		*use_bench = 1;
		i = 2;
	}
	if (ft_strcmp(argv[i], "--simple") == 0)
		algorithm = 1;
	else if (ft_strcmp(argv[i], "--medium") == 0)
		algorithm = 2;
	else if (ft_strcmp(argv[i], "--complex") == 0)
		algorithm = 3;
	else if (ft_strcmp(argv[i], "--adaptive") == 0)
		algorithm = 4;
	return (algorithm);
}

static char	*call_sort(t_sort_data *data, int sizelist)
{
	if (sizelist == 2)
		return (ft_sort_two(data->list_a, data->ops, data->use_bench),
			"Two elements / O(1)");
	else if (sizelist == 3)
		return (ft_sort_three(data->list_a, data->ops, data->use_bench),
			"Three elements / O(1)");
	else if (sizelist == 5)
		return (ft_sort_five(data->list_a, data->list_b, data->ops,
				data->use_bench), "Five elements / O(1)");
	return (NULL);
}

static char	*ft_call_algorithm(t_sort_data *data)
{
	int	size;

	size = ft_lstsize(*data->list_a);
	if (size == 2 || size == 3 || size == 5)
		return (call_sort(data, size));
	if (data->algorithm_choice == 4)
		data->algorithm_choice = 0;
	if (data->algorithm_choice == 1)
		return (ft_selection_sort(data->list_a, data->list_b, data->ops,
				data->use_bench), "Simple O(n²)");
	if (data->algorithm_choice == 2)
		return (ft_bucket_sort(data->list_a, data->list_b, data->ops,
				data->use_bench), "Medium O(n√n)");
	if (data->algorithm_choice == 3)
		return (ft_radix_sort(data->list_a, data->list_b, data->ops,
				data->use_bench), "Complex O(n log n)");
	return (ft_adaptive_sort(data));
}

static void	ft_call_functions_main(t_sort_data *data, int argc)
{
	int	offset;
	int	newargc;

	offset = 1;
	data->use_bench = 0;
	data->algorithm_choice = verify_flags(data->argv, &data->use_bench);
	if (data->algorithm_choice)
		offset++;
	if (data->use_bench)
		offset++;
	data->argv = ft_prepare_numbers(data->argv, argc, offset, &newargc);
	ft_build_list(data->list_a, data->argv, newargc);
	ft_set_index(*data->list_a);
	if (ft_issorted(*data->list_a))
		return ;
	data->disorder = compute_disorder(*data->list_a);
	if (data->use_bench)
		ft_bench(ft_call_algorithm(data), data->disorder, data->ops);
	else
		ft_call_algorithm(data);
}

int	main(int argc, char **argv)
{
	t_stack			*list_a;
	t_stack			*list_b;
	t_operations	ops;
	t_sort_data		data;

	if (argc < 2)
		return (0);
	list_a = NULL;
	list_b = NULL;
	ft_fillstruct_ops(&ops);
	data.list_a = &list_a;
	data.list_b = &list_b;
	data.ops = &ops;
	data.argv = argv;
	ft_call_functions_main(&data, argc);
	ft_exit(&list_a, &list_b);
	return (0);
}
