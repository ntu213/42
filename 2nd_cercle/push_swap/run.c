/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:55:03 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/31 11:01:38 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_end(t_tab *a. t_tab *b)
{
	int	i;
	int	cache;

	i = b->size - 1;
	cache = b->tab[i]->val;
	while (i > -1)
	{
		if (b->tab[i]->val > cache)
			return (0);
		cache = b->tab[i]->val;
		i--;
	}
	i = 0;
	while (i < a->size)
	{
		if (a->tab[i]->val > cache)
			return (0);
		cache = a->tab[i]->val;
		i--;
	}
	return (1);
}

void	ft_run(t_tab *a)
{
	t_tab	*b;

	b = ft_init_tab(NULL, 0);
}