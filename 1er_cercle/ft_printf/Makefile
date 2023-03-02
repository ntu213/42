NAME = libftprintf.a

SRC =	ft_printf.c	tester.c

OBJ = ${SRC:.c=.o}

LIB = ft_printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all