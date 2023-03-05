NAME = libftprintf.a

SRC =	ft_printf.c			new_base.c			ft_printf_functions.c	\
		ft_putchar_fd.c		ft_itoa.c			ft_putstr_fd.c			\
		ft_strlen.c			ft_strlcat.c		ft_strdup.c

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