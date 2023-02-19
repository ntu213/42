void ft_lstiter(t_list *lst, void (*f)(void *))
{
	while((*lst).next)
	{
		f((*lst).content);
		*lst = (*lst).next;
	}
}