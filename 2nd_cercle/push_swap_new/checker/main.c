/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:26:19 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 17:02:55 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lst_max(t_lst *lst)
{
	int	n;

	n = lst->val;
	while (lst)
	{
		if (lst->val > n)
			n = lst->val;
		lst = lst->next;
	}
	return (n);
}

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
	ft_checker(&lst);
	ft_free_lst(lst);
	return (0);
}
