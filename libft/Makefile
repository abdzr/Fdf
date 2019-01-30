# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azarzor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 21:34:04 by azarzor           #+#    #+#              #
#    Updated: 2018/10/24 09:44:14 by azarzor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror ft*.c
	ar rc libft.a *.o

clean:
	rm -rf ft*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
