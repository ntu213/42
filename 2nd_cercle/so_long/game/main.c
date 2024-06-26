/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 09:43:17 by vgiraudo         ###   ########.fr       */
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
		free(new);
	}
	if (fd < 0)
		ft_printf("[\e[0;31mError\e[0;37m] %s: Invalid file\n", str);
	return (fd);
}

t_map	**ft_init(t_map **str, int j, char *arg, int fd)
{
	t_map	**new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(t_map *), j + 1);
	new[j] = ft_calloc(sizeof(t_map), 1);
	while (i < j)
	{
		new[i] = str[i];
		i++;
	}
	if (j)
		free(str);
	new[j]->fd = fd;
	new[j]->width = 0;
	new[j]->height = 0;
	new[j]->name = arg;
	new[j]->map = NULL;
	new[j]->ok = 0;
	return (new);
}

void	ft_fullfree(t_map **str, int j)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < j)
	{
		while (str[i]->map[a])
		{
			free(str[i]->map[a]);
			a++;
		}
		close(str[i]->fd);
		free(str[i]->map);
		free(str[i]);
		i++;
		a = 0;
	}
	free(str);
}

int	ft_hp(int argc)
{
	if (HP < 0)
	{
		ft_printf("[\e[0;31mError\e[0;37m] Invalid amount of HP: %d %s\n",
			HP, "is too low!");
		return (0);
	}
	if (HP > 10)
	{
		ft_printf("[\e[0;31mError\e[0;37m] Invalid amount of HP: %d %s\n",
			HP, "is too high!");
		return (0);
	}
	if (HP == 0)
	{
		ft_printf("[\e[0;31mError\e[0;37m] Bro, your character is stillborn...\n");
		return (0);
	}
	if (argc == 1)
		ft_printf("[\e[0;31mError\e[0;37m] I need an argument\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	**obj;
	int		fd;
	int		i;
	int		j;

	i = 1;
	j = 0;
	obj = NULL;
	if (!ft_hp(argc))
		return (0);
	while (i < argc)
	{
		fd = is_file(argv[i]);
		if (fd >= 0)
		{
			obj = ft_init(obj, j, argv[i], fd);
			j++;
		}
		i++;
	}
	if (j)
		ft_first(obj, j);
	ft_fullfree(obj, j);
	return (1);
}
