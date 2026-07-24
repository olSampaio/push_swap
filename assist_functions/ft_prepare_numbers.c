/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:30:01 by armarque          #+#    #+#             */
/*   Updated: 2026/07/23 23:57:08 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	see_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**ft_prepare_numbers(char **argv, int argc, int offset, int *count)
{
	char	**newnums;

	if (argc - offset == 1)
	{
		newnums = ft_split(argv[offset], ' ');
		*count = see_size(newnums);
		return (newnums);
	}
	*count = argc - offset;
	return (argv + offset);
}
