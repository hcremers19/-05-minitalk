# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:08:58 by hcremers          #+#    #+#              #
#    Updated: 2022/11/10 11:14:36 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= $(NAME1) $(NAME2)
NAME1	= client
NAME2	= server

SRC		= $(SRC1) $(SRC2)
SRC1	= client.c
SRC2	= server.c

OBJ		= $(OBJ1) $(OBJ2)
OBJ1	= $(SRC1:.c=.o)
OBJ2	= $(SRC2:.c=.o)

UTILS	= utils
LIB		= libutils.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ1) $(OBJ2)
			make -C $(UTILS)/
			$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(UTILS)/$(LIB)
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) $(UTILS)/$(LIB)

clean:
			make clean -C $(UTILS)/
			$(RM) $(wildcard *.o)

fclean:		clean
			make fclean -C $(UTILS)/
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re zip
