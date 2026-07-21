/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:03:59 by lusampai          #+#    #+#             */
/*   Updated: 2026/06/17 14:15:38 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *type, ...)
{
	size_t	idx;
	va_list	parameter;
	int		size;
	int		ret;

	if (!type)
		return (-1);
	va_start(parameter, type);
	idx = 0;
	size = 0;
	while (type[idx])
	{
		if (type[idx] == '%')
		{
			ret = ft_discover_type(type[idx + 1], &parameter);
			if (ret == -1)
				return (-1);
			size += ret;
			idx++;
		}
		else
			size += write(1, &type[idx], 1);
		idx++;
	}
	return (va_end(parameter), size);
}
