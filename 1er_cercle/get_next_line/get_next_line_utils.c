#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd <0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	
	line = get_line();
	buffer = next_line();
}