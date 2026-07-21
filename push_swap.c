/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 15:59:03 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void ft_call_algorithm(t_stack **list_a, t_stack **list_b,int algorithm_choice, int disorder)
{
	if (algorithm_choice == 1)
		ft_selection_sort(list_a, list_b);
	else if (algorithm_choice == 2)
		ft_bucket_sort(list_a, list_b);
	else if (algorithm_choice == 3)
		ft_radix_sort(list_a, list_b);
	else if (algorithm_choice == 0)
	{
		if (disorder < 20)
			ft_selection_sort(list_a, list_b);
		else if (20 <= disorder && disorder <= 50)
			ft_bucket_sort(list_a, list_b);
		else
			ft_radix_sort(list_a, list_b);
	}	
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int *use_bench;
	int algorithm_choice;
	int disorder;

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
	disorder = compute_disorder(list_a);
	ft_call_algorithm(&list_a, &list_b, algorithm_choice, disorder);
	printf("\nLISTA ORGANIZADA\n\n");
	while(list_a)
	{
		printf("%d ", list_a -> value);
		list_a = list_a -> next;
	}
	return (0);
}
