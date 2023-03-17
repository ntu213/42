/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/17 18:18:08 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * main() prend en compte chaque element donne en argument, et tente d'executer le jeu a la suite.
 *  	renvoie une erreur si un jeu ne peut etre lance et passe au suivant
 *
 *
 *
 *
 */

int	is_file(char *str, int *fd)
{
	char	*new;
	char	*cat;

	cat = malloc(9);
	cat = "../maps/";
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		new = ft_strjoin(ft_strdup(str), ".ber");
	ft_printf("fd: %d\n", *fd);
		*fd = open(ft_strjoin(cat, new), O_RDONLY);
		free(new);
	}
	else
		*fd = open(ft_strjoin(cat, str), O_RDONLY);;
	if (*fd < 0)
	{
		ft_printf("[Error] %s: Invalid map\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 1;
	ft_printf("%d\n", argc);
	while(i < argc)
	{
		if (is_file(argv[i], &fd))
		{
			ft_printf("%s\n", argv[i]);
			//executer le code
		}
		i++;
	}
	return (1);
}