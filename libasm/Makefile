NAME = libasm.a

SRCS = ft_strlen.s ft_write.s ft_strcpy.s ft_strcmp.s ft_read.s ft_strdup.s
SRCS_C = help.c
SRCS_BONUS = ft_atoi_base_bonus.s ft_list_push_front_bonus.s ft_list_size_bonus.s ft_list_remove_if_bonus.s ft_list_sort_bonus.s

OBJS = $(SRCS:.s=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.s=.o)

%.o: %.c
	gcc -g -Wall -Werror -Wextra -c $< -o $@

%.o: %.s
	nasm -g -f elf64 $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_C)
	ar rcs $(NAME) $(OBJS) $(OBJS_C)

bonus: $(OBJS) $(OBJS_C) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_C) $(OBJS_BONUS)

test: bonus
	gcc -g -Wall -Wextra -Werror -o tester tester.c $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_C) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f tester

re: fclean all