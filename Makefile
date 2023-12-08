# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:45:18 by ffleitas          #+#    #+#              #
#    Updated: 2023/12/08 15:41:42 by ffleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server 
CLIENT = client
PRINTF = ./ft_printf/libftprintf.a

SRC_SERVER = server.c 
SRC_CLIENT = client.c 

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(PRINTF) :
	@$(MAKE) -s -C ./ft_printf

$(SERVER) : $(OBJS_SERVER) $(PRINTF)
	@$(CC) $(OBJS_SERVER) $(PRINTF) -o server 

$(CLIENT) : $(OBJS_CLIENT) $(PRINTF)
	@$(CC) $(OBJS_CLIENT) $(PRINTF) -o client
	@echo "\nMinitalk is ready!\n"

clean:
	@$(MAKE) -s -C ./ft_printf clean
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) 

fclean: clean
	@$(MAKE) -s -C ./ft_printf fclean
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re