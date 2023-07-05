NAME = ex01

SRC =	Contact.cpp\
		PhoneBook.cpp\
		main.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME):
	@c++ $(FLAGS) $(SRC) -o $(NAME)
	@echo ✅ File created: $(NAME)

clean:

fclean:
	@rm -f $(NAME)
	@echo ✅ File deleted: $(NAME)

re: fclean all