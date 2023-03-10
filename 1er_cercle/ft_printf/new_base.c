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

char	*int_base(unsigned int n, char *base, t_obj *item, int kebab)
{
	int		base_count;

	base_count = ft_strlen(base);
	if (n)
	{
		int_base(n / base_count, base, item, 1);
		write(1, &base[n % base_count], 1);
		item->total++;
	}
	else if (!kebab)
	{
		write(1, "0", 1);
		item->total++;
	}
	return ("");
}

void	ft_ptochar(void *p, char *base, t_obj *item, int n)
{
	int					baselen;
	unsigned long int	intt;

	intt = (unsigned long int)p;
	baselen = ft_strlen(base);
	if (!n && !p)
	{
		write(1, "(nil)", 5);
		item->total += 5;
	}
	else if (intt)
	{
		ft_ptochar((void *)(intt / baselen), base, item, 1);
		write(1, &base[intt % baselen], 1);
		item->total++;
	}
	else
	{
		write(1, "0x", 2);
		item->total += 2;
	}
}

void	ft_reverse(char *res)
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

void	ft_write_it(const char *origin, int i, t_obj *item)
{
	write(1, &origin[i], 1);
	item->total++;
}
