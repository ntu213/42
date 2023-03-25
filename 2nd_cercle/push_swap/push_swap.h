#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
//#include <stdlib.h>	//--> NULL

int		ft_atoi(const char *str);
int		ft_tablen(int *tab);
void	ft_run(int *taba, int n);
void	ft_putstr(char *str);
void	ft_push(int *tab1, int *tab2);
void	ft_ss(int *taba, int *tabb);
void	ft_swap(int *tab);
void	ft_rotate(int *tab);
void	ft_rr(int *taba, int *tabb);
void	ft_revrot(int *tab);
void	ft_rrr(int *taba, int *tabb);
void	ft_init_tab(int *tab, int n);