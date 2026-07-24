/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:13:46 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:04:04 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_lowercase(va_list *parameter, int fd)
{
	unsigned int	alphanum;

	alphanum = va_arg(*parameter, unsigned int);
	return (ft_putnbr_base(alphanum, "0123456789abcdef", fd));
}

int	ft_print_x_uppercase(va_list *parameter, int fd)
{
	unsigned int	alphanum;

	alphanum = va_arg(*parameter, unsigned int);
	return (ft_putnbr_base(alphanum, "0123456789ABCDEF", fd));
}
