/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:55:44 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:56:06 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

int	ft_is_ok(t_lst *a, t_lst *b)
{
	int	val;

	if (!a || b)
		return (0);
	val = a->val;
	a = a->next;
	while (a)
	{
		if (a->val < val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_check_str(char *str, t_lst **a, t_lst **b)
{
	if (ft_strstr(str, "ra\n"))
		*a = ft_ra(*a, *b);
	else if (ft_strstr(str, "rb\n"))
		*b = ft_rb(*a, *b);
	else if (ft_strstr(str, "rr\n"))
		ft_rr(a, b);
	else if (ft_strstr(str, "rra\n"))
		*a = ft_rra(*a, *b);
	else if (ft_strstr(str, "rrb\n"))
		*b = ft_rrb(*a, *b);
	else if (ft_strstr(str, "rrr\n"))
		ft_rrr(a, b);
	else if (ft_strstr(str, "pa\n"))
		ft_pa(a, b);
	else if (ft_strstr(str, "pb\n"))
		ft_pb(a, b);
	else if (ft_strstr(str, "sa\n"))
		ft_sa(a, b);
	else if (ft_strstr(str, "sb\n"))
		ft_sb(a, b);
	else if (ft_strstr(str, "ss\n"))
		ft_ss(a, b);
	else
		return (ft_putstr("Error\n"), 0);
	return (1);
}

void	ft_free_gnl(char *str)
{
	while (str)
	{
		free(str);
		str = get_next_line(0);
	}
}

void	ft_checker(t_lst **lst)
{
	int		i;
	char	*str;
	t_lst	*lst2;

	i = 0;
	str = get_next_line(0);
	while (str)
	{
		if (!ft_check_str(str, lst, &lst2))
			return (ft_free_gnl(str));
		free(str);
		str = get_next_line(0);
		i++;
	}
	if (ft_is_ok(*lst, lst2))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
