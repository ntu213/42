
NAME = push_swap

SRC =	main.c	lib.c\

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo ✅ File created: $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)
	@echo ✅ Deleted file: $(NAME)

re: fclean all