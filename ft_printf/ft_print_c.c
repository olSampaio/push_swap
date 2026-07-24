/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:28:38 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 21:45:59 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list *parameter, int fd)
{	
	char	c;

	c = (char)va_arg(*parameter, int);
	write(fd, &c, 1);
	return (1);
}
