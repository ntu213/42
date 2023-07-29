/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:42:23 by dfleury           #+#    #+#             */
/*   Updated: 2023/06/05 13:05:36 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 *  Retourne une str :
 *       jusqu'au \n et un peu plus (en fonction de BUFFER_SIZE)
 *    OU jusqu'a EOF s'il n'y a pas de RC
 *
 *  Ne fait pas de read s'il y a deja une \n dans str
 */
static char	*read_until_rc(int fd, char *sstr)
{
	char	*buff;
	int		read_count;
	char	*tmp;

	read_count = 1;
	while (!ft_strchr_x(sstr, '\n') && read_count != 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_count] = '\0';
		tmp = ft_strjoin_x(sstr, buff);
		free(sstr);
		sstr = ft_strdup(tmp);
		free(buff);
		free(tmp);
	}
	return (sstr);
}

/*
 *	Param	:	sstr 		: la chaine static
 *	Return	:	return_str 	: jusqu'au \n (compris)  OU EOF
 */
static char	*get_return_str(char *sstr)
{
	int		i;
	char	*return_str;

	i = 0;
	if (!sstr[i])
		return (NULL);
	while (sstr[i] && sstr[i] != '\n')
		i++;
	return_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!return_str)
		return (NULL);
	i = 0;
	while (sstr[i] && sstr[i] != '\n')
	{
		return_str[i] = sstr[i];
		i++;
	}
	if (sstr[i] == '\n')
	{
		return_str[i] = sstr[i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

static char	*get_rest_str(char *sstr)
{
	int		i;
	int		j;
	char	*rest_str;

	i = 0;
	while (sstr[i] && sstr[i] != '\n')
		i++;
	if (!sstr[i])
	{
		free(sstr);
		return (NULL);
	}
	rest_str = (char *)malloc(sizeof(char) * (ft_strlen_x(sstr) - i + 1));
	if (!rest_str)
		return (NULL);
	i++;
	j = 0;
	while (sstr[i])
		rest_str[j++] = sstr[i++];
	rest_str[j] = '\0';
	free(sstr);
	return (rest_str);
}

/*
 * // ! AJOUT DE ;
 * 	if (ft_strlen(sstr) == 0)
 *		free(sstr);
 */
char	*get_next_line(int fd)
{
	static char	*sstr;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sstr = read_until_rc(fd, sstr);
	if (!sstr)
		return (NULL);
	return_str = get_return_str(sstr);
	sstr = get_rest_str(sstr);
	if (ft_strlen(sstr) == 0)
		free(sstr);
	return (return_str);
}

/*
=== Description
Write a function that returns a line read from a file descriptor

=== Parameters
fd: The file descriptor to read from

=== Return value
Read line: correct behavior
NULL: there is nothing else to read, or an error occurred

=== External functs.
read, malloc, free

=== Infos

• Repeated calls to your get_next_line() function should let you read the text
 file pointed to by the file descriptor, one line at a time.

• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.

• Make sure that your function works as expected both when reading a file and
 when reading from the standard input.

• Please note that the returned line should include the terminating \n
 character, except if the end of file was reached and does not end with
 a \n character.

• Because you will have to read files in get_next_line(), add this option to
 your compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the
 Moulinette in order to test your code.

We must be able to compile this project with and without the -D
BUFFER_SIZE flag in addition to the usual flags. You can choose the
default value of your choice.

• You will compile your code as follows (a buffer size of 42 is used as an
 example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

• We consider that get_next_line() has an undefined behavior if the file pointed
 to by the file descriptor changed since the last call whereas read() didn’t
 reach the end of file.

• We also consider that get_next_line() has an undefined behavior when reading
a binary file.

*/