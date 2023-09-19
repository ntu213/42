
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*
int	hash:		ajouter "0x" devant pour %X et %x
int	space:		met un espace avant
int	plus:		si int positif, afficher '+'
int	total:		le nombre total de caracteres ecrits
*/

typedef struct s_obj
{
	int	hash;
	int	space;
	int	plus;
	int	total;
}	t_obj;

char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd, t_obj *item);
char	*ft_strdup(const char *s);

#endif
