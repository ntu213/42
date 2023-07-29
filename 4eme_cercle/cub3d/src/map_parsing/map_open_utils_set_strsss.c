/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open_utils_set_strsss.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:03:29 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
 *	Return un tableau de char** avec seulement les INFOS DE LA MAP
 *	(sans la description)
 */
void	set_map_infos_strs(t_data *data, int map_start_line_index)
{
	char	**map_infos_strs;
	int		d;

	map_infos_strs = ft_calloc(map_start_line_index + 1, sizeof(char *));
	d = 0;
	while (d < map_start_line_index && data->map->mapfile_strs[d])
	{
		map_infos_strs[d] = ft_strdup(data->map->mapfile_strs[d]);
		d++;
	}
	data->map->mapfile_strs_infos = map_infos_strs;
}

/*
 *	Return un tableau de char** avec seulement la DESCCRIPTION DE LA MAP
 *	(sans les infos)
 */
void	set_map_desc_strs(t_data *data, int map_start_line_index)
{
	char	**map_desc_strs;
	int		d;

	map_desc_strs = ft_calloc(ft_strs_size(data->map->mapfile_strs)
			- map_start_line_index + 1, sizeof(char *));
	d = 0;
	while (data->map->mapfile_strs[map_start_line_index])
		map_desc_strs[d++] = ft_strdup(
				data->map->mapfile_strs[map_start_line_index++]);
	data->map->mapfile_strs_desc = map_desc_strs;
}

static int	get_map_start_line_index_sub(char *trim_line)
{
	return (!ft_str_startswith(trim_line, "NO")
		&& !ft_str_startswith(trim_line, "SO")
		&& !ft_str_startswith(trim_line, "WE")
		&& !ft_str_startswith(trim_line, "EA")
		&& !ft_str_startswith(trim_line, "F")
		&& !ft_str_startswith(trim_line, "C")
		&& !ft_str_startswith(trim_line, "DOOR")
		&& !ft_str_startswith(trim_line, "FLOOR")
		&& !ft_str_startswith(trim_line, "CEIL")
		&& !ft_str_startswith(trim_line, "GUN"));
}

/*
 *	Renvoie l'index de la 1ere ligne de la description de la map
 *	exit si on ne trouve pas cette ligne
 */
int	get_map_start_line_index_or_exit(t_data *data)
{
	char	*trim_line;
	int		l;

	l = 0;
	while (data->map->mapfile_strs[l])
	{
		trim_line = ft_strtrim_white_space(data->map->mapfile_strs[l]);
		if (ft_strlen(trim_line) > 0 && get_map_start_line_index_sub(trim_line))
		{
			free(trim_line);
			return (l);
		}
		l++;
		free(trim_line);
	}
	free_data_and_exit(data);
	exit (print_error_message("Map desc missing !"));
}

/*
 *	Return un tableau de char** avec toutes les lignes du fichier
 *
 * 	Notes:
 *		- ft_split supprime les lignes vides.
 *		- En cas d'erreur d'ouverture, on free et on exit
 *
 */
void	set_mapfile_strs_or_exit(t_data *data, char *filename)
{
	char	*mapfile_str;

	ft_printf("Opening the map "C_BLU"%s"C_NOR"...\n", filename);
	mapfile_str = ft_readfile(filename);
	if (!mapfile_str || ft_strlen(mapfile_str) == 0)
	{
		free(data->map);
		free_str_if_exist(mapfile_str);
		exit (print_error_message("Can't open file !"));
	}
	ft_printf(C_GRE" OK"C_NOR"\n");
	data->map->mapfile_strs = ft_split(mapfile_str, '\n');
	free(mapfile_str);
	if (ft_strs_size(data->map->mapfile_strs) == 0)
	{
		free_data_and_exit(data);
		exit (print_error_message("Empty file !"));
	}
	data->map->mapfile_strs = data->map->mapfile_strs;
}
