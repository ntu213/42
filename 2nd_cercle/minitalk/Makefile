NAME = minitalk

CLIENTNAME = client

SERVERNAME = server

CLIENTSRC = client.c

SERVERSRC = server.c

SRC = libft.c ft_itoa.c exit.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(CLIENTSRC) $(SRC) -o $(CLIENTNAME)
	@echo ✅ File created: $(CLIENTNAME)
	@gcc $(FLAGS) $(SERVERSRC) $(SRC) -o $(SERVERNAME)
	@echo ✅ File created: $(SERVERNAME)

clean:
	@rm -f $(CLIENTNAME) $(SERVERNAME)
	@echo ✅ File deleted: $(CLIENTNAME)
	@echo ✅ File deleted: $(SERVERNAME)

fclean: clean

re: fclean all