int ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while ((*lst).next)
	{
		lst = (*lst).next;
		i++;
	}
	return (i);
}
