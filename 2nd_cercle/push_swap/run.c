#include "push_swap.h"

void	ft_init_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}

int	ft_istop(int *taba, int size_a)
{
	int	i;
	int	pos;
	int	mem;

	i = 0;
	mem = taba[0];
	pos = i;
	while (i < size_a)
	{
		if (pos > taba[i])
		{
			mem = taba[i];
			pos = i;
		}
		i++;
	}
	if (pos <= size_a / 2)
		return (1);
	return (0);
}

int	ft_getmin(int *taba, int *tabb, int size_a, int size_b)
{
	int	pos;
	int	i;

	i = 0;
	pos = taba[0];
	while (i < size_a)
	{
		if (taba[i] < pos)
			pos = taba[i];
		i++;
	}
	i = 0;
	while (i < size_b)
	{
		if (tabb[i] < pos)
			pos = tabb[i];
		i++;
	}
	return (pos);
}

int	ft_end(int *taba, int *tabb, int size_a, int size_b)
{
	int	pos;
	int	i;

	pos = ft_getmin(taba, tabb, size_a, size_b);
	i = 1;
	if (pos > taba[0])
		return (0);
	while (i < size_a)
	{
		if (taba[i] < taba[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_pb(int *taba, int *tabb, int *size_a, int *size_b)
{
	ft_push(tabb, taba, size_b, size_a);
printf("%d | %d\n", *size_a, *size_b);
	*size_b++;
	*size_a--;
printf("%d | %d\n", *size_a, *size_b);
	write(1, "pb\n", 3);
}

void	ft_pa(int *taba, int *tabb, int *size_a, int *size_b)
{
	ft_push(taba, tabb, size_a, size_b);
printf("%d | %d\n", *size_a, *size_b);
	*size_a++;
	*size_b--;
printf("%d | %d\n", *size_a, *size_b);
	write(1, "pa\n", 3);
}

void	ft_debug(int *taba, int *tabb, int size_a, int size_b)
{
	int	i = 0;

	while (i < 4)
	{
		printf("%d | %d | %d | %d\n", taba[i], tabb[i], size_a, size_b);
		i++;
	}
}

void	ft_run(int *taba, int size_a)
{
	int	tabb[size_a];
	int	size_b;
	int	hasrun;

	size_b = 0;
	hasrun = 0;
	ft_init_tab(tabb, size_a);
	while (!ft_end(taba, tabb, size_a, size_b))
	{
ft_debug(taba, tabb, size_a, size_b);
		while (hasrun-- && taba[0] == ft_getmin(taba, tabb, size_a, size_b))
			ft_pb(taba, tabb, &size_a, &size_b);
		if (ft_istop(taba, size_a))
			ft_top(taba, tabb, &size_a, &size_b);
		else
			ft_bot(taba, tabb, &size_a, &size_b);
		hasrun = 1;
	}
	while (size_b)
		ft_pa(taba, tabb, &size_a, &size_b);
}