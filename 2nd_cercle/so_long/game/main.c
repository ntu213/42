/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/21 20:12:57 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * main() prend en compte chaque element donne en argument, et tente d'executer
 *  	le jeu a la suite. Renvoie une erreur si un jeu ne peut etre lance et
 *  	passe au suivant
 *
 * is_file() prend en parametre un num de fichier a ouvrir avec ou sans ".ber"
 *  	et le recherche dans le dossier maps/ de la racine. Si le fichier
 *  	n'existe pas, ecrit que la map est invalide et renvoie 0. renvoie 1
 *  	si le fichier a ete trouve
 *
 * ft_init() prend en parametres un tableau de tableaux str, un int j, un char*
 *  	arg, et un int fd et ajoute comme elements a str fd sur les indices
 *  	pairs et arg sur les impairs.		|arg = nom de fichier|
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

char	**ft_init(t_map **str, int j, char *arg, int fd)
{
	t_map	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_map *) * j);
	if (j)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		free(str);
	}
	new[j] = ft_itoa(fd);
	new[j + 1] = arg;
	new[j + 2] = NULL;
	return (new);
}

void	ft_temp(char **str)
{
	int	i;

	ft_printf("OKOK\n");
	i = 0;
	while (str[i])
	{
		ft_printf("fd: %s, file: %s\n", str[i], str[i + 1]);
		i += 2;
	}
}

void	ft_fullfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
			free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_map	**obj;
	int		fd;
	int		i;
	int		j;

	i = 1;
	j = 0;
	ft_printf("argc: %d\n\n", argc);
	while (i < argc)
	{
		fd = is_file(argv[i]);
		if (fd >= 0)
		{
			ft_printf("Valid map: %s\n", argv[i]);
			obj = ft_init(obj, j, argv[i], fd);
			j++;
		}
		i++;
	}
//	ft_temp(obj);
	if (j)
		ft_first(obj);
	ft_printf("\nrun %d\n", j);
	ft_fullfree(obj);
	return (1);
}
