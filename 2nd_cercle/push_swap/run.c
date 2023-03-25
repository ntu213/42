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
	ft_push(tabb, taba);

	int i = 0;
	printf(" A | B\n");
	while (i < n)
	{
		printf("%d | %d\n", taba[i], tabb[i]);
		i++;
	}
}