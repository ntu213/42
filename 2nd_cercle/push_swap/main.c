#include "push_swap.h"

int	ft_error(int n)
{
	write(2, "Error\n", 6);
	return (n);
}

int	ft_ok_2(int n, int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (n == tab[i])
			return (0);
		i++;
	}
	tab[i] = n;
	return (1);
}

int	ft_ok(char **strr, int n, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < n)
	{
		if (!ft_ok_2(ft_atoi(strr[j]), tab))
			return (0);
		while (strr[j][i])
		{
			if (!(strr[j][i] >= '0' && strr[j][i] <= '9'))
				return(0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	tab[argc - 1];

	i = 1;
	if (argc == 1 || !ft_ok(argv, argc, tab))
		return (ft_error(0));
	ft_run(tab, argc - 1);
	return (1);
}