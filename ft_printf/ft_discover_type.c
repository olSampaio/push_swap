/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discover_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:13:13 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/17 14:18:45 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_discover_type(char specifier, va_list *parameter)
{	
	if (specifier == 'c')
		return (ft_print_c(parameter));
	else if (specifier == 's')
		return (ft_print_s(parameter));
	else if (specifier == 'p')
		return (ft_print_p(parameter));
	else if (specifier == 'd')
		return (ft_print_d(parameter));
	else if (specifier == 'i')
		return (ft_print_i(parameter));
	else if (specifier == 'u')
		return (ft_print_u(parameter));
	else if (specifier == 'x')
		return (ft_print_x_lowercase(parameter));
	else if (specifier == 'X')
		return (ft_print_x_uppercase(parameter));
	else if (specifier == '%')
		return (ft_print_percentage());
	else
		return (-1);
}
