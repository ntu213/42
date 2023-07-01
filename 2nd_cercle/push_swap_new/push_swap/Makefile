
NAME = push_swap

SRC =	main.c	\
		lib.c	\
		algo2.c	\
		instructions.c	\
		instructions2.c	\
		instructions3.c	\
		parser.c	\
		parser2.c	\
		quicksort.c	\
		quicksort2.c	\
		utils.c	\
		utils2.c	\
		utils3.c	\
		utils4.c	\

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