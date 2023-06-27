/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:26:19 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/27 13:43:22 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_init_lst(int val, int pos, t_lst *first, t_lst *nextof)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	new->val = val;
	new->pos = pos;
	new->category = -1;
	new->first = first;
	new->next = NULL;
	if (nextof)
	{
		new->next = nextof->next;
		new->first = nextof->first;
		nextof->next = new;
	}
	return (new);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_lstprev(t_lst *lst, t_lst *addr)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next != addr)
		lst = lst->next;
	return (lst);
}

void	ft_newfirst(t_lst *first, t_lst *new)
{
	while (first)
	{
		first->first = new;
		first = first->next;
	}
}

void	ft_free_lst(t_lst *lst)
{
	t_lst	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

int	ft_iswhitespace(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

int	ft_haswspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
			return (1);
		i++;
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_isfullwspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_lst_count(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_lst_min(t_lst *lst)
{
	int	n;

	n = lst->val;
	while (lst)
	{
		if (lst->val < n)
			n = lst->val;
		lst = lst->next;
	}
	return (n);
}

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

/*******************************_INSTRUCTIONS_*********************************/

t_lst	*ft_ra(t_lst *a, t_lst *b)
{
	t_lst	*first;

	first = a->next;
	(void)b;
	ft_lstlast(a)->next = a;
	a->next = NULL;
	ft_newfirst(first, first);
	return (a->first);
}

t_lst	*ft_rb(t_lst *a, t_lst *b)
{
	t_lst	*first;

	first = b->next;
	(void)a;
	ft_lstlast(b)->next = b;
	b->next = NULL;
	ft_newfirst(first, first);
	return (b->first);
}

void	ft_rr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_ra(*a, *b);
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rb(*a, *b);
		*b = (*b)->first;
	}
}

t_lst	*ft_rra(t_lst *a, t_lst *b)
{
	t_lst	*tmp;

	(void)b;
	ft_newfirst(a, ft_lstlast(a));
	tmp = ft_lstlast(a);
	ft_lstprev(a, tmp)->next = NULL;
	tmp->next = a;
	return (a->first);
}

t_lst	*ft_rrb(t_lst *a, t_lst *b)
{
	t_lst	*tmp;

	(void)a;
	ft_newfirst(b, ft_lstlast(b));
	tmp = ft_lstlast(b);
	ft_lstprev(b, ft_lstlast(b))->next = NULL;
	tmp->next = b;
	return (b->first);
}

void	ft_rrr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_rra(*a, *b);
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rrb(*a, *b);
		*b = (*b)->first;
	}
}

void	ft_pa(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_newfirst(*b, *b);
}

void	ft_pb(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_newfirst(*a, *a);
}

void	ft_sa(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	(void)b;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	ft_sb(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	(void)a;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	ft_ss(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

/**********************************_PARSER_************************************/

t_lst	*ft_init_spaces(char *tmp)
{
	int		i;
	char	*str;
	t_lst	*new;

	i = 0;
	if (ft_isfullwspaces(tmp))
		return (NULL);
	str = ft_strdup(tmp);
	new = ft_init_lst(ft_atoi(str), -1, NULL, NULL);
	new->first = new;
	while (str[i])
	{
		while (!ft_iswhitespace(str[i]) && str[i])
			i++;
		while (ft_iswhitespace(str[i]))
			i++;
		if (!str[i])
			break ;
		new = ft_init_lst(ft_atoi(str + i), -1, NULL, new);
	}
	free(str);
	return (new->first);
}

t_lst	*ft_init_nospaces(char **str)
{
	int		i;
	t_lst	*new;

	i = 2;
	new = ft_init_lst(ft_atoi(str[1]), -1, NULL, NULL);
	new->first = new;
	while (str[i])
	{
		new = ft_init_lst(ft_atoi(str[i]), -1, NULL, new);
		i++;
	}
	return (new->first);
}

int	ft_hasdubs(t_lst *lst)
{
	t_lst	*lst2;
	int		i;
	int		j;

	i = 0;
	while (lst)
	{
		j = 0;
		lst2 = lst->first;
		while (lst2)
		{
			if (lst->val == lst2->val && i != j)
				return (1);
			lst2 = lst2->next;
			j++;
		}
		lst = lst->next;
		i++;
	}
	return (0);
}

int	ft_lst_count_nocat(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->category < 0)
			i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_give_category(t_lst *lst, int i)
{
	int		n;
	t_lst	*first;

	i = 0;
	n = (ft_lst_count(lst) / 10) + (ft_lst_count(lst) % 10 / 5);
	first = lst->first;
	if (!n)
		n++;
	while (i < 10)
	{
		while (lst)
		{
			if (lst->pos / n == i)
				lst->category = i + 1;
			lst = lst->next;
		}
		lst = first;
		i++;
	}
	while (lst)
	{
		if (lst->category < 0)
			lst->category = 10;
		lst = lst->next;
	}
}

/*********************************_CHECKING_***********************************/

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
			return ;
		free(str);
		str = get_next_line(0);
		i++;
	}
	if (ft_is_ok(*lst, lst2))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

/***********************************_MAIN_*************************************/

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
	if (ft_hasdubs(lst))
		return (ft_free_lst(lst), ft_putstr("Error\n"), 0);
	ft_checker(&lst);
	ft_free_lst(lst);
	return (0);
}
