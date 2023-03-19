NAME = so_long

SRC =	ft_printf/*.c	game/*.c	GNL/get_next_line.c	GNL/get_next_line_utils.c

LIB = ft_printf.h

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = -lm -lX11 -lXext

CC = gcc

all: mlx $(NAME)

mlx:
	make -C ./mlx/

$(NAME):
	$(CC) $(SRC) -o $(NAME) mlx/libmlx.a $(LIBFLAGS)

clean:
	rm -f $(NAME)

re: clean all

.PHONY:	mlx