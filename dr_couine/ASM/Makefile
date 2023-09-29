
COOLEEN = Colleen
GRACE = Grace
SULLY = Sully

COOL_SRC = Colleen.s
COOL_OBJ = ${COOL_SRC:.s=.o}
GRACE_SRC = Grace.s
GRACE_OBJ = ${GRACE_SRC:.s=.o}
SULLY_SRC = Sully.s
SULLY_FAKE = ${addsuffix _*,$(SULLY)}
SULLY_OBJ = ${SULLY_SRC:.s=.o}

CC = nasm
FLAGS =  -f elf64

all: $(COOLEEN) $(GRACE)

%.o:%.s
	@$(CC) $(FLAGS) $@ -o $<


$(COOLEEN):
	@nasm -f elf64 Colleen.s
	@gcc -no-pie Colleen.o -o Colleen -lm

$(GRACE):
	@nasm -f elf64 Grace.s
	@gcc -no-pie Grace.o -o Grace -lm

$(SULLY):
	@nasm -f elf64 Sully.s
	@gcc -no-pie Sully.o -o Sully -lm

clean:
	@rm -f $(COOL_OBJ)
	@rm -f $(GRACE_OBJ)
	@rm -f $(SULLY_OBJ)
	@echo ✅ All sources deleted
 
fclean: clean
	@rm -f $(COOLEEN)
	@echo ✅ File deleted: $(COOLEEN)
	@rm -f $(GRACE)
	@rm -f Grace_kid.s
	@echo ✅ File deleted: $(GRACE)
	@rm -f $(SULLY)
	@rm -f $(SULLY_FAKE)
	@echo ✅ File deleted: $(SULLY)

re: fclean all
