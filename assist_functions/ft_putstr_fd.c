/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:40:54 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:58:42 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	write(fd, s, length);
}
