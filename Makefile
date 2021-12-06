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

$(NAME)

all:
	gcc -Wall -Wextra -Werror -c client.c
	gcc -Wall -Wextra -Werror -c server.c
	gcc -o client client.o libft.a
	gcc -o server server.o

clean:
	rm client.o server.o

fclean:
	rm client server

re: fclean all

.PHONY: all clean fclean re
