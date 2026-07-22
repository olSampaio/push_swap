/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 17:03:46 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "push_swap.h"

static void	ft_build_list(t_stack **list_a, char **argv, int argc)
{
	int		i;
	t_stack	*new_node;
	int		j;

	i = argc - 1;
	while (i >= 1)
	{
		j = 0;
		if (ft_isnumber(argv[i]) == 1)
		{
			new_node = malloc(sizeof(t_stack));
			new_node->value = atoi(argv[i]);
			new_node->index = 0;
			new_node->next = NULL;
			new_node->prev = NULL;
			ft_lstadd_front(list_a, new_node);
		}
		i--;
	}
}

static int	verify_flags(char **argv, int *use_bench)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--medium") == 0)
			return (2);
		else if (ft_strcmp(argv[i], "--complex") == 0)
			return (3);
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			return (0);
		else if (ft_strcmp(argv[i], "--bench") == 0)
			*use_bench = 1;
		i++;
	}
	return (0);
}

static void	ft_call_algorithm(t_stack **list_a, t_stack **list_b,
		int algorithm_choice, int disorder, t_operations *ops)
{	
	if (algorithm_choice == 1)
		ft_selection_sort(list_a, list_b, ops);
	else if (algorithm_choice == 2)
		ft_bucket_sort(list_a, list_b, ops);
	else if (algorithm_choice == 3)
		ft_radix_sort(list_a, list_b, ops);
	else if (algorithm_choice == 0)
	{
		if (disorder < 20)
			ft_selection_sort(list_a, list_b, ops);
		else if (20 <= disorder && disorder <= 50)
			ft_bucket_sort(list_a, list_b, ops);
		else
			ft_radix_sort(list_a, list_b, ops);
	}
}

void	fillstruct(t_operations *ops)
{
	ops->pb = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
}

int	main(int argc, char **argv)
{
	t_stack			*list_a;
	t_stack			*list_b;
	int				use_bench;
	int				algorithm_choice;
	int				disorder;
	t_operations	ops;	

	fillstruct(&ops);
	use_bench = 0;
	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
	{
		printf("Uso: %s <numeros>\n", argv[0]);
		return (1);
	}
	algorithm_choice = verify_flags(argv, &use_bench);
	ft_build_list(&list_a, argv, argc);
	ft_set_index(list_a);
	disorder = compute_disorder(list_a);
	disorder = 50;
	ft_call_algorithm(&list_a, &list_b, algorithm_choice, disorder, &ops);
	return (0);
}
