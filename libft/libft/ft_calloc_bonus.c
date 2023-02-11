#include "libft_bonus.h"

void	*ft_calloc(size_t n, size_t size)
{
	int	i;

	if (n == NULL || size == NULL)
		return (NULL);
	i = malloc(sizeof(size) * n);
	return((void *)i);
}