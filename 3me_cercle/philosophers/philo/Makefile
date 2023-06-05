NAME = minitalk

NAME = philo

SRC = instructions.c	instructions2.c	new.c	libft.c	new2.c

FLAGS = -Wall -Werror -Wextra -pthread

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME)
	@echo ✅ File created: $(NAME)

clean:
	@rm -f $(NAME) $(SERVERNAME)
	@echo ✅ File deleted: $(NAME)

fclean: clean

re: fclean all