NAME = fractol
SRCS = ./Srcs/*.c
INCLDS = ./Inclds/*.h
FLAGS = -Wextra -Werror -Wall
OBJ = *.o

all : $(NAME)

$(NAME) :
	@	make -C libft
	@	gcc $(FLAGS) -c $(SRCS)
	@	gcc -o $(NAME) $(OBJ) libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit
	@	echo "Fractol Created"

clean :
	@	make clean -C libft
	@	rm -rf *.o *.gch

fclean : clean
	@	make fclean -C libft
	@	rm -rf *a fractol
	@	echo "Cleaned"

re : fclean all