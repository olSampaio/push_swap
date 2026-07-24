/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:31 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:03:15 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_putnbr_base(unsigned long long nbr, char *base,
	unsigned long long len, int fd)
{	
	int	qt_print;

	qt_print = 1;
	if (nbr >= len)
		qt_print += ft_print_putnbr_base(nbr / len, base, len, fd);
	write(fd, &base[nbr % len], 1);
	return (qt_print);
}

int	ft_putnbr_base(unsigned long long nbr, char *base, int fd)
{	
	unsigned long long	len;

	len = ft_strlen(base);
	return (ft_print_putnbr_base(nbr, base, len, fd));
}
