#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;
	int		i = 7;

	fd = open("tester", O_RDONLY);
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (i)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("\n|%s|\n", line);
		free(line);
		i--;
		//write(1, "OK", 2);
	}
	return (0);
}