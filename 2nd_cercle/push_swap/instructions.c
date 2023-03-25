#include "push_swap.h"

void	ft_rotate(int *tab)
{
	int	i;
	int	c;

	i = 1;
	c = tab[0];
	while (tab[i])
	{
		tab[i - 1] = tab[i];
		i++;
	}
	tab[i - 1] = c;
}

void	ft_rr(int *taba, int *tabb)
{
	ft_rotate(taba);
	ft_rotate(tabb);
	ft_putstr("rr\n");
}

void	ft_revrot(int *tab)
{
	int	i;
	int	c;

	i = 0;
	while (tab[i])
		i++;
	i--;
	c = tab[i];
	while (i)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = c;
}

void	ft_rrr(int *taba, int *tabb)
{
	ft_revrot(taba);
	ft_revrot(tabb);
	ft_putstr("rrr\n");
}
