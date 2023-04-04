NAME = so_long

SRC =	ft_printf/*.c	game/*.c	GNL/get_next_line.c	GNL/get_next_line_utils.c

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = -lm -lX11 -lXext

CC = gcc

all: mlx $(NAME)

mlx:
	@make -C ./mlx/
	@echo ✅ Compiled mlx

$(NAME):
	@$(CC) $(SRC) -o $(NAME) mlx/libmlx.a $(LIBFLAGS)
	@echo ✅ File created: $(NAME)

clean:
	@rm -f $(NAME)
	@echo ✅ Deleted file: $(NAME)

fclean: clean

re: fclean all

.PHONY:	mlx