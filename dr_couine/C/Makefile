
COOLEEN = Cooleen
GRACE = Grace
SULLY = Sully

COOL_SRC = Colleen.c
COOL_OBJ = ${COOL_SRC:.c=.o}
GRACE_SRC = Grace.c
GRACE_OBJ = ${GRACE_SRC:.c=.o}
SULLY_SRC = Sully.c
SULLY_FAKE = ${addsuffix _*.c,$(SULLY)}
SULLY_OBJ = ${SULLY_SRC:.c=.o}

CC = gcc
FLAGS = -Wall -Werror -Wextra

%.o:%.c
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(COOLEEN) $(GRACE) $(SULLY)

$(COOLEEN): $(COOL_OBJ)
	@$(CC) $(FLAGS) $(COOL_OBJ) -o $(COOLEEN)

$(GRACE): $(GRACE_OBJ)
	@$(CC) $(FLAGS) $(GRACE_OBJ) -o $(GRACE)

$(SULLY): $(SULLY_OBJ)
	@$(CC) $(FLAGS) $(SULLY_OBJ) -o $(SULLY)

clean:
	@rm -f $(COOL_OBJ)
	@rm -f $(GRACE_OBJ)
	@rm -f $(SULLY_OBJ)
	@echo ✅ All sources deleted

fclean: clean
	@rm -f $(COOLEEN)
	@echo ✅ File deleted: $(COOLEEN)
	@rm -f $(GRACE)
	@rm -f Grace_kid.c
	@echo ✅ File deleted: $(GRACE)
	@rm -f $(SULLY)
	@rm -f $(SULLY_FAKE)
	@echo ✅ File deleted: $(SULLY)

re: fclean all
