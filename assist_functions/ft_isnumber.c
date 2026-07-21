/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:57:53 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/21 17:55:17 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		else
			return (1);
		i++;
	}
	return (0);
}