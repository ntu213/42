/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:51:20 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 11:40:03 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// * Supprimer les commentaires : REGEX REPLACE   :    ([ \t]?)*//.*
// * Il restera 2 fonctions interdites a decommenter

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <dirent.h>

# include <math.h> // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! pour modf dans ft_dtoa

# define C_NOR "\x1b[m"

# define C_GRA "\x1b[30m"
# define C_RED "\x1b[31m"
# define C_GRE "\x1b[32m"
# define C_YEL "\x1b[33m"
# define C_BLU "\x1b[34m"
# define C_MAG "\x1b[35m"
# define C_CYA "\x1b[36m"
# define C_WHI "\x1b[37m"

# define B_GRA "\x1b[40m"
# define B_RED "\x1b[41m"
# define B_GRE "\x1b[42m"
# define B_YEL "\x1b[43m"
# define B_BLU "\x1b[44m"
# define B_MAG "\x1b[45m"
# define B_CYA "\x1b[46m"
# define B_WHI "\x1b[47m"

# define S_BOLD "\x1b[1m"
# define S_UNDER "\x1b[4m"
# define S_REV "\x1b[7m"

# define READFILE_BUF_SIZE 200

# define MAX_PATH_LEN 42000	// pour getcwd

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s,	size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

int		ft_countchars_int_base(int n, int base, int count_sign); //* XTRA
int		ft_countchars_int(int n, int count_sign); //* XTRA
int		ft_countchars_uint_base(unsigned int n, int base); //* XTRA
int		ft_countchars_ulong_base(unsigned long n, int base); //* XTRA

int		ft_is_white_space(char c); // !! new for minishell
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

char	*ft_itoa(int n); //* version modifiée

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

void	*ft_memchr(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

int		ft_printchar(char c); //* XTRA    !! renvoi toujour 1, meme pour '\0'
// int		ft_printf(const char *str, ...); // ! XTRA !!!!!! FORBIDEN !
int		ft_printint_abs(int n); //* XTRA
int		ft_printint(int n); //* XTRA
int		ft_printstr(char *s); //* XTRA
int		ft_printuint(unsigned int n); //* XTRA
int		ft_printuint16(unsigned int n, int upcase); //* XTRA
int		ft_printulong16(unsigned long n, int upcase); //* XTRA

int		ft_printxchars(char c, int count); //* XTRA

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c); //* XTRA
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s); //* XTRA

char	*ft_readfile(char *filename); //! XTRA !!!!!!  A MODIFIER !!!!!!!!!!!*/

char	**ft_split(const char *s, char c);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// ** GNL

char	*get_next_line(int fd);
char	*ft_strjoin_x(char *s1, char const *s2);
char	*ft_strchr_x(const char *s, int c);
size_t	ft_strlen_x(const char *str);

int		ft_printf(const char *str, ...);

//  ***	../libft_extra/

DIR		*ft_get_current_dir(void);
char	*ft_read_fd(int fd); // ! unused	// bug ??
int		ft_str_endswith(char *str, char *end);
int		ft_str_equals(char *s1, char *s2);
// char	*ft_str_modify_and_free(char *str, char *newstr);
int		ft_str_startswith(char *str, char *start);
char	*ft_str_replace(char *original, char *search, char *replce);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strs_concat(int strs_count, ...);
void	ft_strs_free(char **strs);
void	ft_strs_multifree(int strs_count, ...);
int		ft_strs_size(char **strs);
void	ft_strs_sort(char **arr);
char	**ft_strsdup(char **strs);
char	*ft_strtrim_white_space(char const *s1);
double	ft_math_abs_double(double dbl);
// char	*get_next_line_simple(int fd);
char	*ft_dtoa(double d);
#endif
