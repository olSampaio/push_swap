# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 16:43:00 by lusampai          #+#    #+#              #
#    Updated: 2026/06/16 17:36:46 by lusampai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RESULTADO FINAL (OUTPUT)
NAME	= libftprintf.a

# FERRAMENTAS PARA COMPILAR
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# ARQUIVOS FONTE (.C)
SRCS	= ft_printf.c ft_discover_type.c ft_print_c.c ft_print_s.c ft_print_d.c ft_print_i.c \
			ft_print_u.c ft_print_p.c ft_print_x_X.c ft_print_percentage.c ft_putnbr_base.c ft_strlen.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c

# OBJETOS GERADOS A PARTIR DOS ARQUIVOS FONTE
OBJS	= $(SRCS:.c=.o)

# COMANDO DE "REMOVE"
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re