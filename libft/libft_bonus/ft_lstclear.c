void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lsti;

	*lsti = *lst;
	while((*lsti).next)
	{
		del((*lsti).content);
		free((*lsti).content);
		*lsti = (*lsti).next;
	}
	(*lst).next = NULL;
}