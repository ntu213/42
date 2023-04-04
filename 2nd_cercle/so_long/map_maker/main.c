/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 08:59:56 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/04 14:54:06 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"

int	ft_argerror(int n, char *str)
{
	ft_printf("[Error] %s\n", str);
	return (n);
}

int	make_file(char *str)
{
	char	*new;
	int		fd;

	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		new = ft_strjoin(str, ".ber", 0);
		new = ft_strjoin("../maps/", new, 2);
		fd = open(new, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(new);
	}
	else
	{
		new = ft_strjoin("../maps/", str, 0);
		fd = open(new, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(new);
	}
	if (fd < 0)
		ft_printf("[Error] %s: Invalid map\n", str);
	return (fd);
}

void	ft_write(char **strr, int size, int fd)
{
	char	*dest;
	int		i;

	dest = malloc(1);
	dest[0] = '\0';
	i = 0;
	while (i < size)
	{
		dest = ft_strjoin(dest, strr[i], 1);
		dest = ft_strjoin(dest, "\n", 1);
		i++;
	}
	write(fd, dest, ft_strlen(dest));
	free(dest);
}

int	ft_ok_const(void)
{
	if (SEED <= 0)
		return (ft_argerror(0, "Invalid Seed"));
	if (WDENSITY < 0)
		return (ft_argerror(0, "Invalid Wall Density"));
	if (CDENSITY <= 0)
		return (ft_argerror(0, "Invalid Collectible Density"));
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		wid;
	int		hei;
	char	*filename;
	char	**strr;

	if (!ft_ok_const())
		return (0);
	if (argc != 4)
		return (ft_argerror(0, "Invalid Number of Arguments"));
	filename = (argv[1]);
	wid = ft_atoi(argv[2]);
	hei = ft_atoi(argv[3]);
	if (wid < 3 || hei < 3 || wid * hei < 15)
		return (ft_argerror(0, "Invalid Arguments"));
	fd = make_file(filename);
	strr = make_map(wid, hei);
	ft_write(strr, hei, fd);
	ft_printf("Map \"%s\" has been created\n", filename);
}
