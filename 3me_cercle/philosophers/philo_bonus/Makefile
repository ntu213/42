NAME = minitalk

NAME = philo_bonus

SRC = instructions.c	instructions2.c	main.c	instructions3.c	main2.c

FLAGS = -Wall -Werror -Wextra -pthread

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME)
	@echo ✅ File created: $(NAME)

clean:

fclean: clean
	@rm -f $(NAME) $(SERVERNAME)
	@echo ✅ File deleted: $(NAME)

re: fclean all