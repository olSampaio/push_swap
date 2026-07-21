/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:36:27 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/17 14:18:25 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(va_list *parameter)
{	
	long	nbr;
	int		len;

	len = 0;
	nbr = va_arg(*parameter, int);
	ft_putnbr_fd(nbr, 1);
	if (nbr <= 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
