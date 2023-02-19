void ft_lstadd_back(t_list **lst, t_list *new)
{
	*lst = ft_lstlast(*lst);
	*(*lst).next = *new;
}