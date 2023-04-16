NAME = so_long

SRC =	ft_printf/*.c	game/*.c

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = -lm -lX11 -lXext

CC = gcc

all: mlx $(NAME)

mlx:
	@make -C ./mlx/ > temp.txt
	@echo ✅ Compiled mlx
	@rm -f temp.txt

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) mlx/libmlx.a $(LIBFLAGS)
	@echo ✅ File created: $(NAME)

clean:
	@rm -f $(NAME)
	@echo ✅ Deleted file: $(NAME)

fclean: clean

re: fclean all

.PHONY:	mlx