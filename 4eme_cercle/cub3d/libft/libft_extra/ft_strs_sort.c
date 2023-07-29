/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Tri un tableau de char * par ordre alphabetique
 *
 *	/!\   CA NE RENVOIT PAS UNC COPIE, mais tri le tableau original
 */
void	ft_strs_sort(char **arr)
{
	int		i;
	int		j;
	char	*temp;
	int		sorted;

	i = 0;
	sorted = 0;
	while (i < ft_strs_size(arr) - 1 && !sorted)
	{
		sorted = 1;
		j = 0;
		while (j < ft_strs_size(arr) - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sorted = 0;
			}
			j++;
		}
		i++;
	}
}
