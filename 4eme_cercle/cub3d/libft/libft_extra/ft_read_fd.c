/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:24:01 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	FONCTION ECRITE A LA RACHE !!!!! A VERIFIER

	UNUSED ????????????????????????


*/
char	*ft_read_fd(int fd)
{
	char	buff[READFILE_BUF_SIZE];
	int		read_count;
	char	*str;
	char	*tmp;

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
	return (str);
}
