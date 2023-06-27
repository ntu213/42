
NAME = checker

SRC =	main.c	lib.c\
		get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c

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