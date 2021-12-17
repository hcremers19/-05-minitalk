# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:08:58 by hcremers          #+#    #+#              #
#    Updated: 2021/12/04 18:09:00 by hcremers         ###   ########.fr        #
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

CC		= gcc
RM		= rm -f
ZIP		= zip

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ1) $(OBJ2)
			make -C utils/
			$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) utils/libutils.a
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) utils/libutils.a

clean:
			make clean -C utils/
			$(RM) $(wildcard *.o)

fclean:		clean
			make fclean -C utils/
			$(RM) $(NAME)

re:			fclean all

zip:		fclean
			$(ZIP) \[05\]minitalk $(wildcard ./*)

.PHONY:		all clean fclean re zip
