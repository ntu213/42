NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = obj



SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_countchars_int_base.c \
		ft_countchars_int.c \
		ft_countchars_uint_base.c \
		ft_countchars_ulong_base.c \
		ft_is_white_space.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printchar.c \
		ft_printint_abs.c \
		ft_printint.c \
		ft_printstr.c \
		ft_printuint.c \
		ft_printuint16.c \
		ft_printulong16.c \
		ft_printxchars.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_readfile.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_printf/ft_printf.c \
		ft_printf/handle_c.c \
		ft_printf/handle_s.c \
		ft_printf/handle_id.c \
		ft_printf/handle_p.c \
		ft_printf/handle_u.c \
		ft_printf/handle_x.c \
		\
		libft_extra/ft_get_current_dir.c \
		libft_extra/ft_read_fd.c \
		libft_extra/ft_str_endswith.c \
		libft_extra/ft_str_equals.c \
		libft_extra/ft_str_replace.c \
		libft_extra/ft_str_startswith.c \
		libft_extra/ft_strcmp.c \
		libft_extra/ft_strs_concat.c \
		libft_extra/ft_strs_free.c \
		libft_extra/ft_strs_multifree.c \
		libft_extra/ft_strs_size.c \
		libft_extra/ft_strs_sort.c \
		libft_extra/ft_strsdup.c \
		libft_extra/ft_strtrim_white_space.c \
		libft_extra/ft_math_abs_double.c \
		libft_extra/ft_dtoa.c \
		## libft_extra/get_next_line_simple.c \
		## libft_extra/ft_str_modify_and_free.c \

#OBJS = ${SRCS:.c=.o}
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

#.c.o :
#	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@




${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

all : ${NAME}






$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/ft_printf
	mkdir -p $(OBJDIR)/libft_extra



clean :
	rm -f ${OBJS} ${OBJS_B}	## DOUBLON ???
	rm -rf $(OBSJ) obj

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re