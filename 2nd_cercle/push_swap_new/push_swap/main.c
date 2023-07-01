/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 08:57:36 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:23:25 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_str(t_lst *lst, char *str)
{
	if ((ft_strstr(*lst->str, "rra\n") && ft_strstr(str, "rrb\n"))
		|| (ft_strstr(*lst->str, "rrb\n") && ft_strstr(str, "rra\n")))
		*lst->str = "rrr\n";
	else if ((ft_strstr(*lst->str, "ra\n") && ft_strstr(str, "rb\n"))
		|| (ft_strstr(*lst->str, "rb\n") && ft_strstr(str, "ra\n")))
		*lst->str = "rr\n";
	else if ((ft_strstr(*lst->str, "sa\n") && ft_strstr(str, "sb\n"))
		|| (ft_strstr(*lst->str, "sb\n") && ft_strstr(str, "sa\n")))
		*lst->str = "ss\n";
	else
	{
		ft_putstr(*lst->str);
		*lst->str = str;
	}
}

/*
void	ft_print_lst(t_lst *lst)
{
	int	i = 0;
	if (!lst)
		printf("%p\n", NULL);
	while (lst)
	{
		printf("%d | %d | %d\n", lst->val, lst->pos, lst->category);
		lst = lst->next;
		i++;
	}
}
*/

int	ft_has_nonum2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0') && !ft_iswhitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_has_nonum(char **argv)
{
	int	j;

	j = 1;
	if (ft_haswspaces(argv[1]))
	{
		if (ft_has_nonum2(argv[1]))
			return (1);
	}
	else
	{
		while (argv[j])
		{
			if (ft_has_nonum2(argv[j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*lst;

	if (argc == 1)
		return (0);
	if (ft_haswspaces(argv[1]))
		lst = ft_init_spaces(argv[1]);
	else
		lst = ft_init_nospaces(argv);
	if (!lst)
		return (ft_putstr("Error\n"), 0);
	if (ft_has_nonum(argv))
		return (ft_putstr("Error\n"), ft_free_lst(lst), 0);
	if (ft_hasdubs(lst))
		return (ft_free_lst(lst), ft_putstr("Error\n"), 0);
	if (ft_lstsize(lst) < 50)
		lst = ft_kebab(lst);
	else
		lst = ft_quicksort(lst);
	ft_free_lst(lst);
	return (0);
}
