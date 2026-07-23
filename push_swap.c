/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/23 12:52:48 by lusampai         ###   ########.fr       */
=======
/*   Updated: 2026/07/23 12:30:13 by armarque         ###   ########.fr       */
>>>>>>> 9579c2304b7cf8d885d889aeeb2553ad5ba798a4
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

<<<<<<< HEAD
=======
static void	ft_build_list(t_stack **list_a, char **argv, int argc)
{
	int		i;
	t_stack	*new_node;
	long	value;

	i = argc - 1;
	while (i >= 1)
	{
		if (ft_isnumber(argv[i]) == 1)
		{
			value = ft_atoi(argv[i]);
			if (value > INT_MAX || value < INT_MIN)
				ft_error(list_a);
			if (ft_is_repeated(*list_a, value))
				return (ft_error(list_a));
			new_node = malloc(sizeof(t_stack));
			new_node->value = (int)value;
			new_node->index = 0;
			new_node->next = NULL;
			new_node->prev = NULL;
			ft_lstadd_front(list_a, new_node);
		}
		else
			ft_error(list_a);
		i--;
	}
}

>>>>>>> 9579c2304b7cf8d885d889aeeb2553ad5ba798a4
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
		algorithm = 0;
	return (algorithm);
}

static char	*ft_call_algorithm(t_stack **list_a, t_stack **list_b,
		int algorithm_choice, int disorder, t_operations *ops)
{
	int	sizelist;

	sizelist = ft_lstsize(*list_a);
	if (algorithm_choice == 1)
		return (ft_selection_sort(list_a, list_b, ops), "Simple / O(n²)");
	else if (algorithm_choice == 2)
		return (ft_bucket_sort(list_a, list_b, ops), "Medium / O(n√n)");
	else if (algorithm_choice == 3)
		return (ft_radix_sort(list_a, list_b, ops), "Complex / O(n log n)");
	else if (algorithm_choice == 0)
	{
		if ((sizelist <= 3) || (disorder < 20))
			return (ft_selection_sort(list_a, list_b, ops), "Adaptive / O(n²)");
		else if ((sizelist <= 5) || (20 <= disorder && disorder <= 50))
			return (ft_bucket_sort(list_a, list_b, ops), "Adaptive / O(n√n)");
		else
			return (ft_radix_sort(list_a, list_b, ops), "Adaptive/ O(n log n)");
	}
	return (0);
}

static void	ft_call_functions_main(int argc, char **arguments, t_stack **list_a, t_stack **list_b, t_operations *ops)
{
	int		algorithm_choice;
	int		disorder;
	char	*algorithm_name;
	int		use_bench;
	
	use_bench = 0;
	algorithm_choice = verify_flags(arguments, &use_bench);
	ft_build_list(list_a, arguments, argc);
	ft_set_index(*list_a);
	disorder = compute_disorder(*list_a);
	algorithm_name = ft_call_algorithm(list_a, list_b, algorithm_choice, disorder / 100, ops);
	if(use_bench == 1)
		ft_bench(algorithm_name, disorder, ops);
}

int	main(int argc, char **argv)
{
	t_stack			*list_a;
	t_stack			*list_b;
	t_operations	ops;
	// char			**arguments;

	// arguments = ft_split(*argv, ' ');
	ft_fillstruct_ops(&ops);
	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
	{
		printf("Uso: %s <numeros>\n", argv[0]);
		return (1);
	}
	ft_call_functions_main(argc, argv, &list_a, &list_b, &ops);
	return (0);
}
