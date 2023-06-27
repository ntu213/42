/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 08:57:36 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/27 15:53:09 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**********************************_UTILS_*************************************/

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

void	ft_newfirst(t_lst *first, t_lst *new)
{
	while (first)
	{
		first->first = new;
		first = first->next;
	}
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

void	ft_val_pos(t_lst *lst, int val, int pos)
{
	while (lst)
	{
		if (lst->val == val)
			lst->pos = pos;
		lst = lst->next;
	}
}

int	ft_lstsize(t_lst *lst)
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

int	ft_is_category_in_lst(t_lst *lst, int cat)
{
	while (lst)
	{
		if (lst->category == cat)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_lst	*ft_lst_cat_max(t_lst *lst, int cat)
{
	t_lst	*res;

	res = NULL;
	while (!res && lst)
	{
		if (lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->pos > res->pos && lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

t_lst	*ft_lst_cat_min(t_lst *lst, int cat)
{
	t_lst	*res;

	res = NULL;
	while (!res && lst)
	{
		if (lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->pos < res->pos && lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

int	ft_diff(int n1, int n2)
{
	int	res;

	res = n1 - n2;
	if (res < 0)
		res *= -1;
	return (res);
}

int	ft_mindiff(int n, int max, int min)
{
	int	res;

	res = ft_diff(n, max);
	if (res > ft_diff(n, min))
		res = ft_diff(n, min);
	if (res > ft_diff(0, max))
		res = ft_diff(0, max);
	if (res > ft_diff(0, min))
		res = ft_diff(0, min);
	return (res);
}

//renvoie 1 pour mettre en haut, 0 sinon
int	ft_best_way(t_lst *lst, int cat)
{
	int	i;
	int	size;
	int	minpos;
	int	maxpos;

	i = 0;
	size = ft_lstsize(lst);
	while (lst)
	{
		if (lst == ft_lst_cat_max(lst->first, cat))
			maxpos = i;
		else if (lst == ft_lst_cat_min(lst->first, cat))
			minpos = i;
		lst = lst->next;
		i++;
	}
	i = ft_mindiff(size, minpos, maxpos);
	if (i == ft_diff(size, minpos) || i == ft_diff(size, maxpos))
		return (0);
	return (1);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] == s1[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

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

void	ft_give_pos(t_lst *lst)
{
	int		old;
	int		new;
	int		i;
	t_lst	*lst2;

	i = 1;
	old = ft_lst_min(lst);
	new = ft_lst_max(lst);
	ft_val_pos(lst, old, 0);
	while (lst->next)
	{
		lst2 = lst->first;
		new = ft_lst_max(lst->first);
		while (lst2)
		{
			if (lst2->val < new && lst2->val > old)
				new = lst2->val;
			lst2 = lst2->next;
		}
		old = new;
		ft_val_pos(lst->first, old, i);
		lst = lst->next;
		i++;
	}
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

/*******************************_INSTRUCTIONS_*********************************/

t_lst	*ft_ra(t_lst *a, t_lst *b, char *str)
{
	t_lst	*first;

	first = a->next;
	(void)b;
	ft_lstlast(a)->next = a;
	a->next = NULL;
	ft_newfirst(first, first);
	ft_print_str(a, str);
	return (a->first);
}

t_lst	*ft_rb(t_lst *a, t_lst *b, char *str)
{
	t_lst	*first;

	first = b->next;
	(void)a;
	ft_lstlast(b)->next = b;
	b->next = NULL;
	ft_newfirst(first, first);
	ft_print_str(b, str);
	return (b->first);
}

void	ft_rr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_ra(*a, *b, "");
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rb(*a, *b, "");
		*b = (*b)->first;
	}
	ft_print_str(*a, "rr\n");
}

t_lst	*ft_rra(t_lst *a, t_lst *b, char *str)
{
	t_lst	*tmp;

	(void)b;
	ft_newfirst(a, ft_lstlast(a));
	tmp = ft_lstlast(a);
	ft_lstprev(a, tmp)->next = NULL;
	tmp->next = a;
	ft_print_str(a, str);
	return (a->first);
}

t_lst	*ft_rrb(t_lst *a, t_lst *b, char *str)
{
	t_lst	*tmp;

	(void)a;
	ft_newfirst(b, ft_lstlast(b));
	tmp = ft_lstlast(b);
	ft_lstprev(b, ft_lstlast(b))->next = NULL;
	tmp->next = b;
	ft_print_str(b, str);
	return (b->first);
}

void	ft_rrr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_rra(*a, *b, "");
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rrb(*a, *b, "");
		*b = (*b)->first;
	}
	ft_print_str(*a, "rrr\n");
}

void	ft_pa(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_newfirst(*b, *b);
	ft_print_str(*a, "pa\n");
}

void	ft_pb(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_newfirst(*a, *a);
	ft_print_str(*b, "pb\n");
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
	ft_print_str(*a, "sa\n");
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
	ft_print_str(*b, "sb\n");
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
	ft_print_str(*a, "ss\n");
}

/*******************************_QUICKSORTING_*********************************/

/*
**	ft_ra(a, b, "ra\n");
**	ft_rb(a, b, "rb\n");
**	ft_rr(&a, &b);
**	ft_rra(a, b, "rra\n");
**	ft_rrb(a, b, "rrb\n");
**	ft_rrr(&a, &b);
**	ft_pa(&a, &b);
**	ft_pb(&a, &b);
*/

void	ft_on_top(t_lst **a, t_lst **b, int cat)
{
	while (ft_is_category_in_lst(*a, cat))
	{
		if ((*a)->category == cat)
			ft_pb(a, b);
		else
			*a = ft_ra(*a, *b, "ra\n");
	}
}

void	ft_1_to_6(t_lst **a, t_lst **b)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		if ((*a)->category >= 1 && (*a)->category <= 6)
		{
			ft_pb(a, b);
			if ((*b)->category == 2 || (*b)->category == 5)
				*b = ft_rb(*a, *b, "rb\n");
		}
		else
			*a = ft_ra(*a, *b, "ra\n");
		i++;
	}
}

void	ft_7_to_10(t_lst **a, t_lst **b)
{
	while (ft_is_category_in_lst(*a, 7) || ft_is_category_in_lst(*a, 8))
	{
		if ((*a)->category == 7 || (*a)->category == 8)
		{
			ft_pb(a, b);
			if ((*b)->category == 8)
				*b = ft_rb(*a, *b, "rb\n");
		}
		else
			*a = ft_ra(*a, *b, "ra\n");
	}
	ft_on_top(a, b, 9);
	ft_on_top(a, b, 10);
}

void	ft_sort_ba(t_lst **a, t_lst **b, int cat)
{
	while (ft_is_category_in_lst(*b, cat))
	{
		if (*b == ft_lst_cat_min(*b, cat))
		{
			ft_pa(a, b);
			if (ft_lstsize(*a) > 1)
				*a = ft_ra(*a, *b, "ra\n");
		}
		else if (*b == ft_lst_cat_max(*b, cat))
			ft_pa(a, b);
		else
		{
			if (ft_best_way(*b, cat))
				*b = ft_rb(*a, *b, "rb\n");
			else
				*b = ft_rrb(*a, *b, "rrb\n");
		}
	}
	if (ft_lstlast(*a))
		while (ft_lstlast(*a)->category == cat && ft_lstsize(*a) > 1
			&& (ft_lstlast(*a) != ft_lst_cat_max(*a, cat)
				|| ft_lst_cat_max(*b, cat)))
			*a = ft_rra(*a, *b, "rra\n");
}

void	ft_do_ss(t_lst **a, t_lst **b, int hicat, int locat)
{
	if (*a)
	{
		if ((*a)->next)
		{
			if ((*a)->category == hicat && (*a)->next->category == hicat
				&& (*a)->next->pos < (*a)->pos)
				ft_sa(a, b);
		}
	}
	if (*b)
	{
		if ((*b)->next)
		{
			if ((*b)->category == locat && (*b)->next->category == locat
				&& (*b)->next->pos > (*b)->pos)
				ft_sb(a, b);
		}
	}
}

void	ft_sem_sort(t_lst **a, t_lst **b, int hicat, int locat)
{
	while (ft_is_category_in_lst(*b, locat) || ft_is_category_in_lst(*b, hicat))
	{
		if ((*b)->category == locat || (*b)->category == hicat)
		{
			ft_pa(a, b);
			if ((*a)->category == locat)
				*a = ft_ra(*a, *b, "ra\n");
		}
		else
			*b = ft_rb(*a, *b, "rb\n");
	}
	ft_on_top(a, b, hicat);
	ft_sort_ba(a, b, hicat);
}

void	ft_sort_aa(t_lst **a, t_lst **b, int cat)
{
	while (ft_lstlast(*a)->category == cat)
	{
		*a = ft_rra(*a, *b, "rra\n");
		if ((*a)->pos != (*a)->next->pos - 1)
			ft_pb(a, b);
	}
}

void	ft_give_str(t_lst *lst, char **str)
{
	while (lst)
	{
		lst->str = str;
		lst = lst->next;
	}
}

t_lst	*ft_quicksort(t_lst *a)
{
	t_lst	*b;
	char	*str;

	b = NULL;
	str = "";
	ft_give_str(a, &str);
	ft_give_pos(a);
	ft_give_category(a, 0);
	ft_1_to_6(&a, &b);
	ft_7_to_10(&a, &b);
	ft_sort_ba(&a, &b, 10);
	ft_sort_ba(&a, &b, 9);
	ft_sort_ba(&a, &b, 8);
	ft_sort_ba(&a, &b, 7);
	ft_sem_sort(&a, &b, 6, 1);
	ft_sem_sort(&a, &b, 5, 2);
	ft_sem_sort(&a, &b, 4, 3);
	ft_sort_aa(&a, &b, 3);
	ft_sort_ba(&a, &b, 3);
	ft_sort_aa(&a, &b, 2);
	ft_sort_ba(&a, &b, 2);
	ft_sort_aa(&a, &b, 1);
	ft_sort_ba(&a, &b, 1);
	ft_print_str(a, "");
	return (a);
}

/**********************************_KEBABS_************************************/

int	ft_is_end(t_lst *a, t_lst *b)
{
	int		n;
	t_lst	*first;

	first = a;
	n = a->val;
	while (a)
	{
		if (a->val < n)
			return (0);
		n = a->val;
		a = a->next;
	}
	n = first->val;
	while (b)
	{
		if (b->val > n)
			return (0);
		n = b->val;
		b = b->next;
	}
	return (1);
}

int	ft_is_on_top(t_lst *a, t_lst *b)
{
	int	i;
	int	target;

	i = 0;
	target = ft_lst_min(a);
	while (a && a->val != target)
	{
		a = a->next;
		i++;
	}
	if (i > ft_lstsize(a) / 2)
		return (0);
	return (1);
}

t_lst	*ft_kebab(t_lst *a)
{
	t_lst	*b;
	char	*str;

	b = NULL;
	str = "";
	ft_give_pos(a);
	ft_give_str(a, &str);
	while (!ft_is_end(a, b))
	{
		if (a->next && a->next->pos == a->pos - 1)
			ft_sa(&a, &b);
		else if (b && a->pos == b->pos + 1)
			ft_pb(&a, &b);
		else if (ft_is_on_top(a, b))
			a = ft_ra(a, b, "ra\n");
		else
			a = ft_rra(a, b, "rra\n");
	}
	while (b)
		ft_pa(&a, &b);
	ft_print_str(a, "");
	return (a);
}

/***********************************_MAIN_*************************************/

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
	if (ft_lstsize(lst) < 30)
		lst = ft_kebab(lst);
	else
		lst = ft_quicksort(lst);
	ft_free_lst(lst);
	return (0);
}
