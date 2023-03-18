/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:05:09 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/18 20:05:47 by vgiraudo         ###   ########.fr       */
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
	if (freee == 1)
		free(s1);
	else if(freee == 2)
		free(s2);
	return (str);
}

char	*get_file(int fd)
{
	int		size;
	int		index;
	char	*res;
	char	*temp;

	size = 50;
	res = malloc(1);
	res = "";
	temp = malloc(size + 1);
	while (1)
	{
		index = read(fd, temp, size);
		if (!index)
			break;
		temp[index] = 0;
	ft_printf("OK\n");
		res = ft_strjoin(res, temp, 1);
		free(temp);
	ft_printf("OK\n");
	}
	return (res);
}

int	ft_lines(char *file, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	*x = i;
	j = 0;
	while(file[i])
	{
		if (file[i] == '\n')
		{
			*y++;
			j = 0;
		}
		if (j > *x)
			return (0);
		i++;
	}
	return (i);
}

int	ft_ok_file(int *width, int *height, int fd, char *filename)
{
	int		x;
	int		y;
	char	*file;

	y = 0;
	file = get_file(fd);
	ft_printf("OK\n");
	if (!ft_lines(file, &x, &y))
		return (0);
}
