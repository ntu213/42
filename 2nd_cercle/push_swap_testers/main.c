#include "push_swap.h"

int	ft_error(int n)
{
	write(2, "Error\n", 6);
	return (n);
}

int	ft_ok_2(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
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
		if (!ft_ok_2(ft_atoi(strr[j]), tab, j - 1))
			return (0);
		while (strr[j][i])
		{
			if (!((strr[j][i] >= '0' && strr[j][i] <= '9') || strr[j][0] == '-'))
				return(0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	ft_verif(char **str, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (!ft_ok_2(ft_atoi(str[j]), tab, j))
			return (0);
		while (str[j][i])
		{
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][0] == '-'))
				return(0);
			i++;
		}
		j++;
		i = 0;
	}
	return (j);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	int		i;
	int		verif;
	int		arg;
	int		tab[argc - 1];
	char	**str;

	i = 1;
	str = ft_split(argv[1], ' ');
	verif = 0;
	arg = argc - 1;
	if (argc == 2)
	{
		arg = ft_verif(str, tab);
		if (!arg)
			return (0);
	}
	else if (argc == 1 || !ft_ok(argv, argc, tab))
		return (ft_error(0));
	ft_free(str);
	ft_run(tab, arg);
	return (1);
}
