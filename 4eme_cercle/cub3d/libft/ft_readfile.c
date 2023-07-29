/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:24:01 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/04 18:16:52 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(char *filename)
{
	char	buff[READFILE_BUF_SIZE];
	int		read_count;
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = ft_strdup("");
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buff, READFILE_BUF_SIZE);
		buff[read_count] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	if (close(fd) == -1)
		return (NULL);
	return (str);
}
