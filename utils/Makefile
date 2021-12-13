# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 14:25:14 by hcremers          #+#    #+#              #
#    Updated: 2021/07/28 14:25:18 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libutils.a

SCRS	= $(wildcard *.c)

OBJS	= ${SCRS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}
			mkdir objs/
			mv $(OBJS) objs/


all:		${NAME}

clean:
			${RM} -r objs/

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
