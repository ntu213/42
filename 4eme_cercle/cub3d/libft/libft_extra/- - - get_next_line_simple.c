/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   - - - get_next_line_simple.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:42:23 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// * GNL avec un buffer size de 1

static char	*subsubsub(char	*buff)
{
	free(buff);
	return (NULL);
}

static char	*read_until_rc_simple(int fd)
{
	char	*buff;
	int		read_count;
	char	*tmp;
	char	*str;

	read_count = 1;
	str = strdup("");
	while (!ft_strchr_x(str, '\n') && read_count != 0)
	{
		buff = malloc((1 + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		read_count = read(fd, buff, 1);
		if (read_count == -1)
			return (subsubsub(buff));
		buff[read_count] = '\0';
		tmp = ft_strjoin_x(str, buff);
		free(str);
		str = ft_strdup(tmp);
		free(buff);
		free(tmp);
	}
	return (str);
}

char	*get_next_line_simple(int fd)
{
	char	*sstr;

	if (fd < 0)
		return (NULL);
	sstr = read_until_rc_simple(fd);
	return (sstr);
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
 your compiler call: -D SIMPLE_BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the
 Moulinette in order to test your code.

We must be able to compile this project with and without the -D
SIMPLE_BUFFER_SIZE flag in addition to the usual flags. You can choose the
default value of your choice.

• You will compile your code as follows (a buffer size of 42 is used as an
 example):
cc -Wall -Wextra -Werror -D SIMPLE_BUFFER_SIZE=42 <files>.c

• We consider that get_next_line() has an undefined behavior if the file pointed
 to by the file descriptor changed since the last call whereas read() didn’t
 reach the end of file.

• We also consider that get_next_line() has an undefined behavior when reading
a binary file.

*/