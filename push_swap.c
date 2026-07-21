/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 12:48:01 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_build_list(t_stack **list_a, char **argv, int argc)
{
	int		i;
	t_stack	*new_node;

	i = argc - 1;
	while (i >= 1)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->value = atoi(argv[i]);
		new_node->index = 0;
		new_node->next = NULL;
		new_node->prev = NULL;
		ft_lstadd_front(list_a, new_node);
		i--;
	}
}

static int verify_flags(char *argv, int *use_bench)
{
	int i;
	
	i = 0;
	while(argv[i++])
	{
		if (ft_strcmp(&argv[i], "--simple"))
			return 1;
		else if (ft_strcmp(&argv[i], "--medium"))
			return 2;
		else if (ft_strcmp(&argv[i], "--complex"))
			return 3;
		else if (ft_strcmp(&argv[i], "--adaptive"))
			return 0;
		else if (ft_strcmp(&argv[i], "--bench"))
			*use_bench = 1;
	}
	return 0;
}

static void ft_call_algorithm(t_stack **list_a, t_stack **list_b,int algorithm_choice)
{
	if (algorithm_choice == 1)
		ft_selection_sort(list_a, list_b);
	else if (algorithm_choice == 2)
		ft_bucket_sort(list_a, list_b);
	else if (algorithm_choice == 3)
		return ;
	else if (algorithm_choice == 0)
	{
		return ;	
	}	
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int *use_bench;
	int algorithm_choice;

	use_bench = 0;
	list_a = NULL;
	list_b = NULL;	
	if (argc < 2)
	{
		printf("Uso: %s <numeros>\n", argv[0]);
		return (1);
	}
	algorithm_choice = verify_flags(*argv, use_bench);
	ft_build_list(&list_a, argv, argc);
	ft_set_index(list_a);
	compute_disorder(list_a);
	ft_call_algorithm(&list_a, &list_b, algorithm_choice);
	return (0);
}
