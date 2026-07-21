/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:31 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/17 14:12:24 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_putnbr_base(unsigned long long nbr, char *base,
	unsigned long long len)
{	
	int	qt_print;

	qt_print = 1;
	if (nbr >= len)
		qt_print += ft_print_putnbr_base(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
	return (qt_print);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{	
	unsigned long long	len;

	len = ft_strlen(base);
	return (ft_print_putnbr_base(nbr, base, len));
}
