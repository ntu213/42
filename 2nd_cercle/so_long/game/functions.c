/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:05:09 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/25 18:39:38 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnstr(const char *src, const char *obj, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src && !obj)
		return (0);
	if (!obj[0])
		return (0);
	while (n > i && src[i])
	{
		j = 0;
		while (n > i + j && src[i + j] && obj[j] == src[i + j])
		{
			j++;
			if (!obj[j])
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int freee)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j++])
		str[i + j - 1] = s2[j - 1];
	str[i + j - 1] = 0;
	if (freee == 1 || freee == 3)
		free(s1);
	if (freee == 2 || freee == 3)
		free(s2);
	return (str);
}

int	ft_strrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

char	*get_file(int fd)
{
	int		size;
	int		index;
	char	*res;
	char	*true_res;

	size = 15000;
	res = malloc(size + 1);
	index = read(fd, res, size);
	res[index] = 0;
	true_res = ft_strdup(res);
	free(res);
	return (true_res);
}

int	ft_lines(char **file, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (file[j][i])
		{
			i++;
			if (i > x)
				return (0);
		}
		if (i < x)
			return (0);
		j++;
		i = 0;
	}
	if (j < 3 || x < 5)
		return (0);
	return (1);
}

int	ft_ok_char(char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[j])
	{
		while (file[j][i])
		{
			if (!(file[j][i] == '0' || file[j][i] == '1'
					|| file[j][i] == 'P' || file[j][i] == 'C'
					|| file[j][i] == 'E' || file[j][i] == 'M'))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	ft_ok_file(t_map *obj)
{
	char	*file;

	file = get_file(obj->fd);
	ft_printf("OK\n");
	obj->map = ft_split(file, '\n');
	free(file);
	ft_printf("OK\n");
	ft_printf("|%s|\n", obj->map[0]);
	obj->height = ft_strrlen(obj->map);
	obj->width = ft_strlen(obj->map[0]);
	if (!ft_lines(obj->map, obj->width, obj->height) || !ft_ok_char(obj->map) || !ft_ok_border(obj->map))
		return (0);
	ft_printf("\n|x: %d|y: %d|\n", obj->width, obj->height);
	return (1);
}
