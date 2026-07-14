/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:31:30 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/14 19:34:04 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_list_size(t_stack **list_a)
{
	size_t size;
	t_stack *node;

	size = 0;
	node = *list_a;
	while(node)
	{
		node = node -> next;
		size++;
	}
	return (size);
}

static int	ft_nearest_end(t_stack *node, size_t size)
{	
	size_t count_steps;

	count_steps = 0;							// CONTA A QUANTIDADE DE PASSOS PARA CHEGAR ATÉ O FINAL A PARTIR DO ELEMENTO
	while(node -> next)
	{
		count_steps++;
		node = node -> next;
	}
	if(count_steps >= size/2)					// SE A QUANTIDADE DE PASSOS PARA CHEGAR AO FINAL DA LISTA, FOR MAIOR QUE A METADE, EU ESTOU MAIS PERTO DO COMEÇO
		return (1);								// O 1 SIGNIFICA QUE A EXTREMIDADE MAIS PERTO É O COMEÇO OU QUE AS DUAS EXTREMIDADES TEM A MESMA DISTÂNCIA
	else
		return (2);								// O 2 SIGNIFICA QUE A EXTREMIDADE MAIS PERTO É O FINAL
}

static t_stack *ft_get_smaller(t_stack **list_a)
{
	t_stack *smaller;
	t_stack *node;
	
	node = *list_a;
	smaller = node;
	while(node)
	{
		if(smaller -> value > node -> value)
			smaller = node;
		node = node -> next;
	}
	return (smaller);
}

void	ft_selection_sort(t_stack **list_a, t_stack **list_b)
{
	size_t	size;
	t_stack	*smaller;

	size = ft_list_size(list_a);
	while(*list_a)
	{		
		smaller = ft_get_smaller(list_a);
		if (ft_nearest_end(smaller, size) == 1)
		{
			while (*list_a != smaller)
				ra(list_a);
			pb(list_a, list_b);
		}
		else
		{
			while (*list_a != smaller)
				rra(list_a);
			pb(list_a, list_b);
		}
		size--;
	}
	while(*list_b)
		pa(list_a, list_b);
}
