/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:10:34 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/14 10:10:34 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

/*
typedef struct s_list
{
//	int		n;		//savoir si je suis a la 1ere ligne
	int			done;	//savoir si je suis a la fin de mon fichier
	static char	*str;	//ficher extrait
}		t_list;
*/

char	*get_next_line(int fd);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *c);
int		is_line(char *str);
char	*get_str(char *str, int fd);
char	*ft_strdup(const char *s);

#endif