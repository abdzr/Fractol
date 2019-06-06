NAME = fractol
SRCS = ./Srcs/burningship.c\
		./Srcs/calculations2.c\
		./Srcs/colors2.c\
		./Srcs/julia.c\
		./Srcs/juliav4.c\
		./Srcs/main.c\
		./Srcs/mandelbrotv3.c\
		./Srcs/mousehandling.c\
		./Srcs/calculations.c\
		./Srcs/colors.c\
		./Srcs/imagehandling.c\
		./Srcs/juliav3.c\
		./Srcs/keyhooks.c\
		./Srcs/mandelbrot.c\
		./Srcs/mandelbrotv4.c\
		./Srcs/tricorn.c
INCLDS = ./Inclds/fractol.h\
		./Inclds/ft_mlx_keys.h
FLAGS = -Wextra -Werror -Wall
OBJ = burningship.o\
	calculations2.o\
	colors2.o\
	julia.o\
	juliav4.o\
	main.o\
	mandelbrotv3.o\
	mousehandling.o\
	calculations.o\
	colors.o\
	imagehandling.o\
	juliav3.o\
	keyhooks.o\
	mandelbrot.o\
	mandelbrotv4.o\
	tricorn.o

all : $(NAME)

$(NAME) :
	@	make -C libft
	@	gcc $(FLAGS) -c $(SRCS)
	@	gcc -o $(NAME) $(OBJ) libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit
	@	echo "Fractol Created"
	@	mv $(OBJ) ./Objcs 

clean :
	@	make clean -C libft
	@	rm -rf ./Objcs/$(OBJ)

fclean : clean
	@	make fclean -C libft
	@	rm -rf $(NAME)
	@	echo "Cleaned"

re : fclean all