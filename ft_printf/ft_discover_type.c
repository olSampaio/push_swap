/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discover_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:13:13 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 21:49:18 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_discover_type(char specifier, va_list *parameter, int fd)
{	
	if (specifier == 'c')
		return (ft_print_c(parameter, fd));
	else if (specifier == 's')
		return (ft_print_s(parameter, fd));
	else if (specifier == 'p')
		return (ft_print_p(parameter, fd));
	else if (specifier == 'd')
		return (ft_print_d(parameter, fd));
	else if (specifier == 'i')
		return (ft_print_i(parameter, fd));
	else if (specifier == 'u')
		return (ft_print_u(parameter, fd));
	else if (specifier == 'x')
		return (ft_print_x_lowercase(parameter, fd));
	else if (specifier == 'X')
		return (ft_print_x_uppercase(parameter, fd));
	else if (specifier == '%')
		return (ft_print_percentage(fd));
	else
		return (-1);
}
