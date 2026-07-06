/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:18:58 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/06 12:38:06 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new) // LSTADD_FRONT ATUALIZADO PARA LISTA DUPLAMENTE ENCADEADA
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	new -> prev = NULL;
	
	if (*lst)
		(*lst) -> prev = new;
	*lst = new;
}
