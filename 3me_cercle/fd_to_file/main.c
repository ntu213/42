#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *str;
	int rd = 0;
	int fd;

	if (argc != 3)
		return (printf("Error\n"));
	str = malloc(100001);
	rd = read(atoi(argv[1]), str, 100000);
	str[rd] = 0;
	fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, str, strlen(str));
	free(str);
	return (1);
}
