# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 18:59:51 by ffleitas          #+#    #+#              #
#    Updated: 2023/12/04 17:39:48 by ffleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c printf_utils.c printf_hex.c minitalk_utils.c

OBJS = $(SOURCES:.c=.o)

COMPILER = cc -Wall -Wextra -Werror

REMOVER = rm -f 

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(REMOVER) $(OBJS)

fclean: clean
	$(REMOVER) $(NAME)

re: fclean all

.PHONY: all clean fclean re