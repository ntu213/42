#include "push_swap.h"

void	ft_rotate(int *tab, int size)
{
	int	i;
	int	c;

	i = 1;
	c = tab[0];
	while (i < size)
	{
		tab[i - 1] = tab[i];
		i++;
	}
	i--;
	tab[i] = c;
}

void	ft_rr(int *taba, int *tabb, int size_a, int size_b)
{
	ft_rotate(taba, size_a);
	ft_rotate(tabb, size_b);
	ft_putstr("rr\n");
}

void	ft_revrot(int *tab, int size)
{
	int	i;
	int	c;

	c = tab[size - 1];
	i = size - 1;
	while (i)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = c;
}

void	ft_rrr(int *taba, int *tabb, int size_a, int size_b)
{
	ft_revrot(taba, size_a);
	ft_revrot(tabb, size_b);
	ft_putstr("rrr\n");
}
