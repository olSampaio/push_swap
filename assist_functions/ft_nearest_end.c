/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearest_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:45:33 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/22 11:47:18 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nearest_end(t_stack *node, int size)
{	
	int count_steps;

	count_steps = 0;
							// CONTA A QUANTIDADE DE PASSOS PARA CHEGAR ATÉ O FINAL A PARTIR DO ELEMENTO
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