/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:24:24 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/17 14:17:47 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(va_list *parameter)
{
	void	*address;

	address = va_arg(*parameter, void *);
	if (address != NULL)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_base(
				(unsigned long long)address,
				"0123456789abcdef") + 2
		);
	}
	ft_putstr_fd("(nil)", 1);
	return (5);
}
