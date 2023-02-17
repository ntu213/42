/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:08:03 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/15 15:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
void			*content;
struct s_list	*next;
}	t_list;

void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
void	*ft_memchr(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, int n);
char	*ft_strchr(char *s, int c);
int		ft_strlcat(char *dest, const char *src, size_t n);
int		ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *c);
int		ft_strncmp( const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *src, const char *obj, size_t n);
char	*ft_strrchr(char *s, int c);
int		ft_atoi(char *str);
void	*ft_calloc(size_t n, size_t size);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *s1, char const *set);

#endif