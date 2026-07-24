/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:34:10 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:48:07 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_size(int n)
{
	size_t	idx;
	long	number;

	idx = 0;
	number = n;
	if (number <= 0)
	{
		number *= -1;
		idx += 1;
	}
	while (number)
	{
		number /= 10;
		idx++;
	}
	return (idx);
}

char	*ft_itoa(int n)
{
	size_t	idx;
	char	*str;
	long	number;

	number = n;
	idx = count_size(n);
	if (n < 0)
		number *= -1;
	str = malloc((idx + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[idx] = '\0';
	if (n == 0)
		str[0] = '0';
	while (number > 0)
	{
		idx--;
		str[idx] = (number % 10) + 48;
		if (n < 0)
			str[0] = '-';
		number /= 10;
	}
	return (str);
}
