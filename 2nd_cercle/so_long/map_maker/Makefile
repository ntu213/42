NAME =	map_maker

SRC =	*.c\
		../ft_printf/*.c

CONST =	-D SEED=1\
		-D WDENSITY=100\
		-D CDENSITY=5\
		-D MOBS=0

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME) $(CONST)
	@echo ✅ Compiled file: $(NAME)

clean:
	@rm -f $(NAME)
	@echo ✅ Deleted file: $(NAME)

fclean: clean

re: fclean all