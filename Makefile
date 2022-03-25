# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 15:41:19 by hmkrtchy          #+#    #+#              #
#    Updated: 2021/07/28 15:41:23 by hmkrtchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = Server_main
CLIENT   = Client_main
CC	     = gcc
RM		 = rm -f *.o
FLAGS    = -Wall -Werror -Wextra -pthread 


all : $(SERVER) $(CLIENT)

$(SERVER) : Server_main.o utils.o lib.h
	@$(CC) Server_main.o utils.o $(FLAGS) -o $@ 


$(CLIENT) : Client_main.o utils.o lib.h
	@$(CC) Client_main.o utils.o $(FLAGS)-o $@ 

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean:
				$(RM) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(SERVER) $(CLIENT)	

.PHONY:			all clean fclean re
