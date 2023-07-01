/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:27:49 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 17:04:40 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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

char	*get_next_line(int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
void	ft_putstr(char *str);

//CHECKER//

int		ft_strstr(char *s1, char *s2);
int		ft_is_ok(t_lst *a, t_lst *b);
int		ft_check_str(char *str, t_lst **a, t_lst **b);
void	ft_free_gnl(char *str);
void	ft_checker(t_lst **lst);

//PARSER//

t_lst	*ft_init_spaces(char *tmp);
t_lst	*ft_init_nospaces(char **str);
int		ft_hasdubs(t_lst *lst);
int		ft_lst_count_nocat(t_lst *lst);
void	ft_give_category(t_lst *lst, int i);

//INSTRUCTIONS//

t_lst	*ft_ra(t_lst *a, t_lst *b);
t_lst	*ft_rb(t_lst *a, t_lst *b);
void	ft_rr(t_lst **a, t_lst **b);
t_lst	*ft_rra(t_lst *a, t_lst *b);
t_lst	*ft_rrb(t_lst *a, t_lst *b);
void	ft_rrr(t_lst **a, t_lst **b);
void	ft_pa(t_lst **a, t_lst **b);
void	ft_pb(t_lst **a, t_lst **b);
void	ft_sa(t_lst **a, t_lst **b);
void	ft_sb(t_lst **a, t_lst **b);
void	ft_ss(t_lst **a, t_lst **b);

//UTILS//

t_lst	*ft_init_lst(int val, int pos, t_lst *first, t_lst *nextof);
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstprev(t_lst *lst, t_lst *addr);
void	ft_newfirst(t_lst *first, t_lst *new);
void	ft_free_lst(t_lst *lst);
int		ft_iswhitespace(char c);
int		ft_haswspaces(char *str);
int		ft_isfullwspaces(char *str);
int		ft_lst_count(t_lst *lst);
int		ft_lst_min(t_lst *lst);
int		ft_lst_max(t_lst *lst);

#endif