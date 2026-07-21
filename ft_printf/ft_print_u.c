/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:58:30 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/17 14:16:32 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(va_list *parameter)
{
	unsigned int	nbr;	
	int				len;

	len = 0;
	nbr = va_arg(*parameter, unsigned int);
	ft_putnbr_base(nbr, "0123456789");
	if (nbr == 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
