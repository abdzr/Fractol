# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 21:34:04 by azarzor           #+#    #+#              #
#    Updated: 2019/04/30 13:51:16 by azarzor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	@	gcc -c -Wall -Wextra -Werror ft*.c
	@	ar rc libft.a *.o
	@	echo "Library Compiled"

clean:
	@	rm -rf ft*.o

fclean: clean
	@	rm -rf $(NAME)
	@	echo "Library Cleaned"

re: fclean all
