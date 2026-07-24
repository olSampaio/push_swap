/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:02:21 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 21:51:32 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list *parameter, int fd)
{
	char	*str;

	str = va_arg(*parameter, char *);
	if (str != NULL)
	{
		ft_putstr_fd(str, fd);
		return (ft_strlen(str));
	}
	ft_putstr_fd("(null)", 1);
	return (6);
}
