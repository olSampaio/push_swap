/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:58:30 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:02:53 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(va_list *parameter, int fd)
{
	unsigned int	nbr;	
	int				len;

	len = 0;
	nbr = va_arg(*parameter, unsigned int);
	ft_putnbr_base(nbr, "0123456789", fd);
	if (nbr == 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
