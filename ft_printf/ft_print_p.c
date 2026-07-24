/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:24:24 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:03:52 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(va_list *parameter, int fd)
{
	void	*address;

	address = va_arg(*parameter, void *);
	if (address != NULL)
	{
		ft_putstr_fd("0x", fd);
		return (ft_putnbr_base(
				(unsigned long long)address,
				"0123456789abcdef", fd) + 2
		);
	}
	ft_putstr_fd("(nil)", 1);
	return (5);
}
