# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/22 16:49:26 by lusampai          #+#    #+#              #
#    Updated: 2026/07/22 16:55:05 by lusampai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RESULTADO FINAL (OUTPUT)
NAME	= libftprintf.a

# FERRAMENTAS PARA COMPILAR
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# ARQUIVOS FONTE (.C)
SRCS	= push_swap.c compute_disorder.c algorithms/simple_algorithm.c algorithms/medium_algorithm.c algorithms/complex_algorithm.c \
	algorithms/utils/medium_algorithm_utils.c algorithms/utils/complex_algorithm_utils.c operations/ft_push.c operations/ft_rotate.c \
	operations/ft_reverse_rotate.c operations/ft_swap.c assist_functions/ft_atoi.c assist_functions/ft_isdigit.c assist_functions/ft_isnumber.c \
	assist_functions/ft_itoa.c assist_functions/ft_lstadd_front.c assist_functions/ft_lstlast.c assist_functions/ft_lstsize.c \
	assist_functions/ft_nearest_end.c assist_functions/ft_search_index.c assist_functions/ft_set_index.c assist_functions/ft_strcmp.c \

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