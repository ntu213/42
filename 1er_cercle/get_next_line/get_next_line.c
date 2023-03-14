/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:10:31 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/14 10:10:31 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_init_buffer(char **buffer)	//initialise le buffer
{
	*buffer = malloc(2);
	*buffer[0] = 'Z';
	*buffer[1] = 0;
}

char	*get_line(char *str)	//retourne "str" jusqu'a \n compris ou \0
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*clear_line(char *str)	//supprime tout de "str" jusqu'a \n compris
{
	char	*cache;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	cache = malloc(ft_strlen(str) - i + 1);
	j = 0;
	while(str[i + j])
	{
		cache[j] = str[i + j];
		j++;
	}
	str[j] = 0;
	free(str);
	return(cache);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = 0;
	}
	buffer = get_str(buffer, fd);
	if (!ft_strlen(buffer))
	{
		free(buffer);
		return (NULL);
	}
	line = get_line(buffer);
	buffer = clear_line(buffer);
	return (line);
}