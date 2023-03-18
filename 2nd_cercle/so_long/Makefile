NAME = so_long

SRC =	ft_printf/*.c	game/*.c	GNL/get_next_line.c	GNL/get_next_line_utils.c

LIB = ft_printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: mlx $(NAME)
mlx:
	make -C ./mlx/

$(NAME):
	$(CC) $(SRC) -o $(NAME) mlx/libmlx.a -lm -lX11 -lXext

clean:
	rm -f $(NAME)

re: clean all

.PHONY:	mlx