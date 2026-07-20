/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:18:37 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/20 09:38:57 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_index(t_stack *list, int node_value)
{
	int	index;

	index = 0;
	
	while(list)
	{
		if(list -> value < node_value)
			index++;
		list = list -> next;
	}
	return (index);
}

void	ft_set_index(t_stack **list)
{
	t_stack *node;

	node = *list;
	while(node)
	{
		node -> index = ft_search_index(*list, node -> value);
		node = node -> next;
	}
}

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

static void	ft_print_list(t_stack *list)
{
	while (list)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
	{
		printf("Uso: %s <numeros>\n", argv[0]);
		return (1);
	}
	ft_build_list(&list_a, argv, argc);
	ft_set_index(&list_a);
	printf("--- ANTES ---\n");
	ft_print_list(list_a);
	ft_bucket_sort(&list_a, &list_b);
	printf("--- DEPOIS ---\n");
	ft_print_list(list_a);
	return (0);
}