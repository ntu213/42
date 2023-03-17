NAME = so_long

SRC =	ft_printf/*.c	game/*.c

LIB = ft_printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all