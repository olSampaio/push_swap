/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:19:52 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/16 17:29:30 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	character;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	if (number > 9)
		ft_putnbr_fd(number / 10, fd);
	character = ((number % 10) + 48);
	write(fd, &character, 1);
}
