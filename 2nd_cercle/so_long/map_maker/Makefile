NAME =	map_maker

SRC =	*.c\
		../ft_printf/*.c

CONST =	-D SEED=2\
		-D WSIDE=40\
		-D WDENSITY=10\
		-D CDENSITY=5\
		-D MOBS=2

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME) $(CONST) -g
	@echo ✅ Compiled file: $(NAME)

clean:
	@rm -f $(NAME)
	@echo ✅ Deleted file: $(NAME)

fclean: clean

re: fclean all