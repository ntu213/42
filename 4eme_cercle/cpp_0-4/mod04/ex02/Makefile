NAME = ex02

SRC =	main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		Brain.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp


FLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME):
	@c++ $(FLAGS) $(SRC) -o $(NAME)
	@echo ✅ File created: $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)
	@echo ✅ File deleted: $(NAME)

re: fclean all
