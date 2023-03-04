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

char	*int_base(int n, char *base, t_obj *item)//convertit un int en base de "base"
{
	int		base_count;

	base_count = ft_strlen(base);
	if (n)
	{
		int_base(n / base_count, base, item);
		write(1, &base[n % base_count], 1);
		item->total++;
	}
	return ("");
}

void	ft_ptochar(void *p, char *base, t_obj *item)//renvoie l'adresse d'un pointeur "p" convertie en base de "base"
{
	int					baselen;
	unsigned long int	intt = (unsigned long int)p;

	baselen = ft_strlen(base);
	if (intt)
	{
		ft_ptochar((void *)(intt / baselen), base, item);
		write(1, &base[intt % baselen], 1);
		item->total++;
	}
	else
	{
		write(1, "0x", 2);
		item->total += 2;
	}
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
