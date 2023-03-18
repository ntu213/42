/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/18 19:43:48 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * main() prend en compte chaque element donne en argument, et tente d'executer le jeu a la suite.
 *  	renvoie une erreur si un jeu ne peut etre lance et passe au suivant
 *is_file() prend en parametre un num de fichier a ouvrir avec ou sans ".ber" et le recherche dans
 *  	le dossier maps/ de la racine. si le fichier n'existe pas, ecrit que la map est invalide
 *  	et renvoie 0. renvoie 1 si le fichier a ete trouve
 *
 *
 */

int	is_file(char *str)
{
	char	*new;
	int		fd;

	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		new = ft_strjoin(str, ".ber", 0);
		new = ft_strjoin("maps/", new, 2);
		fd = open(new, O_RDONLY);
		free(new);
	}
	else
	{
		new = ft_strjoin("maps/", str, 0);
		fd = open(new, O_RDONLY);
	}
	if (fd < 0)
		ft_printf("[Error] %s: Invalid map\n", str);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		j;
	
	i = 1;
	j = 1;
	ft_printf("%d\n", argc);
	while(i < argc)
	{
		fd = is_file(argv[i]);
		if (fd >= 0)
		{
			ft_printf("%s\n", argv[i]);
			ft_first(fd, argv[i]);
			j++;
		}
		i++;
	}
	return (1);
}
