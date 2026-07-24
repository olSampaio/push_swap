# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusampai <lusampai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/22 16:49:26 by lusampai          #+#    #+#              #
#    Updated: 2026/07/23 22:31:45 by lusampai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RESULTADO FINAL (OUTPUT)
NAME	= push_swap

# PRINTF

FT_PRINTF = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a

# FERRAMENTAS PARA COMPILAR
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# ARQUIVOS FONTE (.C)
SRCS	= push_swap.c compute_disorder.c algorithms/simple_algorithm.c algorithms/medium_algorithm.c algorithms/complex_algorithm.c \
	algorithms/utils/medium_algorithm_utils.c algorithms/utils/complex_algorithm_utils.c operations/ft_push.c operations/ft_rotate.c \
	operations/ft_reverse_rotate.c operations/ft_swap.c assist_functions/ft_atoi.c assist_functions/ft_isdigit.c assist_functions/ft_isnumber.c \
	assist_functions/ft_itoa.c assist_functions/ft_lstadd_front.c assist_functions/ft_lstlast.c assist_functions/ft_lstsize.c \
	assist_functions/ft_nearest_end.c assist_functions/ft_search_index.c assist_functions/ft_set_index.c assist_functions/ft_strcmp.c \
	assist_functions/ft_error.c assist_functions/ft_lstclear.c assist_functions/ft_isrepeated.c assist_functions/ft_issorted.c assist_functions/ft_exit.c \
	assist_functions/ft_split.c assist_functions/ft_fillstruct_ops.c assist_functions/ft_prepare_numbers.c algorithms/ft_sort.c ft_bench.c \
	assist_functions/ft_build_list.c assist_functions/ft_nearest_top.c

# OBJETOS GERADOS A PARTIR DOS ARQUIVOS FONTE
OBJS	= $(SRCS:.c=.o)

# COMANDO DE "REMOVE"
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)

$(FT_PRINTF_LIB): 
	$(MAKE) -C $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(FT_PRINTF) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re