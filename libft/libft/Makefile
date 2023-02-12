# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:51:07 by vgiraudo          #+#    #+#              #
#    Updated: 2023/02/12 15:56:47 by vgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_bzero.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
		ft_isdigit.c	ft_isprint.c	ft_memchr.c		ft_memcmp.c		\
		ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_strchr.c		\
		ft_strlcat.c	ft_strlen.c		ft_strncmp.c	ft_strnstr.c	\
		ft_strrchr.c	ft_strlcpy.c	ft_tolower.c	ft_toupper.c	\
		ft_atoi.c		ft_calloc.c		ft_itoa.c		ft_split.c		\
		ft_strdup.c		ft_strjoin.c	ft_substr.c

SRC_BONUS = 			ft_striteri.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

LIB = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

.c.o:			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

bonus:	$(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all