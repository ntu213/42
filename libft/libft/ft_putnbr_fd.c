#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_reversed(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(src);
	while (j > i)
	{
		str[i] = src[j - i];
		i++;
	}
	return (str);
}

static char	*ft_not_itoa(int n, int is_neg)
{
	char	*str;
	int		i;

	i = is_neg + ft_count(n);
	str[i + 1] = 0;
	while (n)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
	str = ft_reversed(str);
	return (str);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	str = ft_not_itoa(n, is_neg);
	ft_putstr_fd(str, fd);
}
