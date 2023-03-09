#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 5
#  endif

typedef struct s_list
{
	int		n;		//savoir si je suis a la 1ere ligne
	int		done;	//savoir si je suis a la fin de mon fichier
	char	*str;	//ficher extrait
}		t_list;

char	*get_next_line(int fd);
char	*ft_itoa(int n);
size_t	ft_strcat(char *dest, char *src);
size_t	ft_strlen(const char *c);
int		is_line(char *str);
void	get_str(char *str, int size, int fd, int *done);

# endif