#include "get_next_line.h"

void	ft_init_buffer(t_list *buffer, int fd)	//initialise le buffer
{
	char	*file;

	buffer = malloc(sizeof(t_list));
	buffer->done = 0;
	buffer->n = 0;
	buffer->str = "";
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
	line[i] = 0;
	i = 0;
	while (line[i])
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

void	clear_line(char *str)	//supprime tout de "str" jusqu'a \n compris
{
	char	*cache;
	int		i;
	int		j;

	cache = str;
	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	free(str);
	str = malloc(ft_strlen(cache) - i + 1);
	j = 0;
	while(cache[i + j])
	{
		str[j] = cache[i + j];
		j++;
	}
	str[j] = 0;
}

*char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || buffer->done)
		return (NULL);
	if (!buffer->n)
		ft_init_buffer(buffer, fd);
	get_str(buffer->str, BUFFER_SIZE, fd, &buffer->done);
	line = get_line(buffer->str);
	clear_line(buffer->str);
	buffer->n = 1;
	return (line);
}