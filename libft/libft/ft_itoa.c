/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:17:46 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/11 10:17:52 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int i);
int	ft_cache(int *cache);
int	ft_is_neg(int *n, char **str);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		is_neg;
	int		cache;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = ft_is_neg(&n, &str);
	cache = n;
	i = ft_cache(&cache);
	str = malloc(sizeof(char) * (i + is_neg + 1));
	if (!str)
		return (NULL);
	if (is_neg)
		str[0] = '-';
	cache = i;
	while (i--)
	{
		str[cache - i + is_neg - 1] = (n / ft_pow(10, i)) + 48;
		n -= (str[cache - i + is_neg - 1] - 48) * ft_pow(10, i);
	}
	str[cache + is_neg] = 0;
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

int	ft_cache(int *cache)
{
	int	i;

	i = 0;
	if (!*cache)
		return (1);
	while (*cache > 0)
	{
		i++;
		*cache /= 10;
	}
	return (i);
}

int	ft_is_neg(int *n, char **str)
{
	int	i;

	i = 0;
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}
