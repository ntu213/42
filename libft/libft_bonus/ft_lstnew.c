#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*stct;

	(*stct).content = malloc(sizeof(content));
	return (stct);
}
