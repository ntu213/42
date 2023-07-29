/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/09 16:36:42 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_dtoa(double d)
{
	char	*str;
	char	*part_ent;
	char	*part_frac;
	double	frac;
	char	*signe;

	if (d < 0)
		signe = "-";
	else
		signe = "";
	d = fabs(d);
	part_ent = ft_itoa((int) d);
	frac = modf(d, &d) * 1000;
	part_frac = ft_itoa((int) fabs(frac));
	str = ft_strs_concat(4, signe, part_ent, ".", part_frac);
	free(part_ent);
	free(part_frac);
	return (str);
}
