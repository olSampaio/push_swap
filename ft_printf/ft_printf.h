/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:35:10 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 22:02:39 by lusampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(int fd, const char *type, ...);
int		ft_discover_type(char specifier, va_list *parameter, int fd);
int		ft_print_c(va_list *parameter, int fd);
int		ft_print_s(va_list *parameter, int fd);
int		ft_print_p(va_list *parameter, int fd);
int		ft_print_d(va_list *parameter, int fd);
int		ft_print_i(va_list *parameter, int fd);
int		ft_print_u(va_list *parameter, int fd);
int		ft_print_x_lowercase(va_list *parameter, int fd);
int		ft_print_x_uppercase(va_list *parameter, int fd);
int		ft_print_percentage(int fd);
int		ft_putnbr_base(unsigned long long nbr, char *base, int fd);
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif