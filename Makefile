NAME= Fdf
SRCS= *.c
INCLDS= *.h
FLAGS= -Wextra -Werror -Wall
OBJCTS= *.o

all : $(NAME)

$(NAME) :
		make -C libft
		gcc $(FLAGS) -c $(SRCS)
		gcc -o Fdf $(OBJCTS) libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit

clean :
		make clean -C libft
		rm -rf *.o *.gch

fclean : clean
		make fclean -C libft
		rm -rf *a Fdf

re : fclean all
