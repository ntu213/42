#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int	i;
	int	isNeg;
	int	cache;
	char	*invert;
	
	i = 0;
	isNeg = 0;
	if (n < 0)
	{
		isNeg = 1;
		n *= -1;
	}
	cache = n;
	while (cache > 0)
	{
		i++;
		cache /= 10;
	}
	str = malloc(sizeof(char) * (i + isNeg + 1));
	if (isNeg)
		str[0] = '-';
	cache = i;
	while (i)
	{
		str[cache - i + isNeg] = n / ft_pow(10, i - 1);
		i--;
	}
	str[cache + 1 + isNeg] = 0;
	return (str);
}

int	ft_pow(int n, int i)
{
	int	n2;

	n2 = n;
	if (i == 0)
		return (1);
	i--;
	while (i)
	{
		n *= n2;
		i--;
	}
	return (n);
}
	