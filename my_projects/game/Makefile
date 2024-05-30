NAME = run

SRC =	main.cpp

FLAGS = -Wall -Wextra -Werror

FLAGS_2 = -lsqlite3 -lncurses


all: $(NAME)

$(NAME): install
	@c++ $(FLAGS) $(SRC) $(FLAGS_2) -o $(NAME)
	@echo ✅ File created: $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)
	@echo ✅ File deleted: $(NAME)

re: fclean all

install:
	@echo Please enable sudo mode for lib installations
	@sudo apt-get install libsqlite3-dev sqlite3 libncurses5-dev libncursesw5-dev