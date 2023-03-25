#include "push_swap.h"

void	ft_swap(int *tab)
{
	int	i;

	i = tab[0];
	tab[0] = tab[1];
	tab[1] = i;
}

void	ft_ss(int *taba, int *tabb)
{
	ft_swap(taba);
	ft_swap(tabb);
	ft_putstr("ss\n");
}

void	ft_down(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i++;
	while (i)
	{
		tab[i] = tab[i - 1];
		i--;
	}
}

void	ft_up(int *tab)
{
	int	i;

	i = 0;
	while (tab[i + 1])
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = NULL;
}

void	ft_push(int *tab1, int *tab2)
{
	int	i;

	i = 0;
	ft_down(tab1);
	tab1[0] = tab2[0];
	ft_up(tab2);
}