/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:21 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/28 13:15:21 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_base(char c, char *base)//renvoie la valeur ascii de "c" convertie en base de "base"
{
	int		i;
	int		baselen;
	char	*res;

	i = 0;
	baselen = ft_strlen(base);
	while(c / baselen)
	{
		res[i] = base[c % baselen];
		i++;
		c /= baselen;
	}
	res[i] = base[c % baselen];
	res[i + 1] = 0;
	return (res);
}

char	*new_base(char *str, char *base)//execute ft_base pour chaque caractere de "str" et renvoie la chaine creee
{
	int		base_count;
	int		i;
	char	*res;
	char	*temp;

	base_count = ft_strlen(base);
	i = 0;
	res = "";
	while(str[i])
	{
		temp = ft_base(str[i], base);
		ft_strlcat(res, temp, ft_strlen(temp) + 1);
		i++;
	}
	ft_strlcat(res, "\0", 1);
	return (res);
}

char	*int_base(int n, char *base)//convertit un int en base de "base"
{
	int		base_count;
	int		i;
	char	*res;
	char	*temp;

	base_count = ft_strlen(base);
	i = 0;
	res = "";
	while(n)
	{
		temp = ft_base((char)(n % 10), base);
		ft_strlcat(res, temp, ft_strlen(temp) + 1);
		i++;
	}
	ft_strlcat(res, "\0", 1);
	ft_reverse(res);
	return (res);
}

char	*ft_ptochar(void *p, char *base)//renvoie l'adresse d'un pointeur "p" convertie en base de "base"
{
	int				i;
	int				baselen;
	char			*res;
	unsigned long	intt = (unsigned long)p;

	i = 0;
	baselen = ft_strlen(base);
	while(intt / baselen)
	{
		write(1, &base[intt % baselen], 1);
		i++;
		intt /= baselen;
	}
	write(1, &base[intt % baselen], 1);
	return (res);
}

void	ft_reverse(char *res)//inverse une chaine de caracteres, pas besoin de return
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(res) - 1;
	while (i < (j / 2))
	{
		c = res[i];
		res[i] = res[j - i];
		res[j] = c;
		i++;
	}
}
