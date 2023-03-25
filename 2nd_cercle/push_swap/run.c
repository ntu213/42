#include "push_swap.h"

void	ft_init_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = NULL;
		i++;
	}
}

void	ft_run(int *taba, int n)
{
	int	tabb[n];

	ft_init_tab(tabb, n);
	ft_swap(taba);
	int i = 0;
	while (i < n)
	{
		printf("%d | %d\n", tabb[i], taba[i]);
		i++;
	}
}