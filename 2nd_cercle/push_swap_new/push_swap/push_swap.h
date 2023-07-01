/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:01:39 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:27:17 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_lst
{
	int				val;
	int				pos;
	int				category;
	char			**str;
	struct s_lst	*first;
	struct s_lst	*next;
}			t_lst;

//LIB//

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
void	ft_putstr(char *str);

//ALGO 2//

int		ft_is_end(t_lst *a, t_lst *b);
int		ft_is_on_top(t_lst *a, t_lst *b);
t_lst	*ft_kebab(t_lst *a);

//INSTRUCTIONS//

t_lst	*ft_ra(t_lst *a, t_lst *b, char *str);
t_lst	*ft_rb(t_lst *a, t_lst *b, char *str);
void	ft_rr(t_lst **a, t_lst **b);
t_lst	*ft_rra(t_lst *a, t_lst *b, char *str);
t_lst	*ft_rrb(t_lst *a, t_lst *b, char *str);
void	ft_rrr(t_lst **a, t_lst **b);
void	ft_pa(t_lst **a, t_lst **b);
void	ft_pb(t_lst **a, t_lst **b);
void	ft_sa(t_lst **a, t_lst **b);
void	ft_sb(t_lst **a, t_lst **b);
void	ft_ss(t_lst **a, t_lst **b);

//PARSER//

t_lst	*ft_init_spaces(char *tmp);
t_lst	*ft_init_nospaces(char **str);
int		ft_hasdubs(t_lst *lst);
void	ft_give_pos(t_lst *lst);
int		ft_lst_count_nocat(t_lst *lst);
void	ft_give_category(t_lst *lst, int i);

//QUICKSORT//

void	ft_on_top(t_lst **a, t_lst **b, int cat);
void	ft_1_to_6(t_lst **a, t_lst **b);
void	ft_7_to_10(t_lst **a, t_lst **b);
void	ft_sort_ba(t_lst **a, t_lst **b, int cat);
void	ft_do_ss(t_lst **a, t_lst **b, int hicat, int locat);
void	ft_sem_sort(t_lst **a, t_lst **b, int hicat, int locat);
void	ft_sort_aa(t_lst **a, t_lst **b, int cat);
void	ft_give_str(t_lst *lst, char **str);
t_lst	*ft_quicksort(t_lst *a);

//UTILS//

t_lst	*ft_init_lst(int val, int pos, t_lst *first, t_lst *nextof);
void	ft_free_lst(t_lst *lst);
int		ft_iswhitespace(char c);
int		ft_haswspaces(char *str);
int		ft_isfullwspaces(char *str);
void	ft_newfirst(t_lst *first, t_lst *new);
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstprev(t_lst *lst, t_lst *addr);
int		ft_lst_count(t_lst *lst);
int		ft_lst_min(t_lst *lst);
int		ft_lst_max(t_lst *lst);
void	ft_val_pos(t_lst *lst, int val, int pos);
int		ft_lstsize(t_lst *lst);
int		ft_is_category_in_lst(t_lst *lst, int cat);
t_lst	*ft_lst_cat_max(t_lst *lst, int cat);
t_lst	*ft_lst_cat_min(t_lst *lst, int cat);
int		ft_diff(int n1, int n2);
int		ft_mindiff(int n, int max, int min);
int		ft_best_way(t_lst *lst, int cat);
int		ft_strstr(char *s1, char *s2);
void	ft_print_str(t_lst *lst, char *str);

#endif