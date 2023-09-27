#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i = 5;
	if (i <= 0)
		return (0);
	i--;
	char content[1000] = "#include <stdlib.h>%c#include <stdio.h>%c%cint main()%c{%c	int i = %d;%c	if (i <= 0)%c		return (0);%c	i--;%c	char content[1000] = %c%s%c;%c	char filename[70];%c	char execname[50];%c	char command[300];%c	sprintf(execname, %cSully_%cd%c, i);%c	sprintf(filename, %c%cs.c%c, execname);%c	void *pointer = fopen(filename, %cw%c);%c	fprintf(pointer, %c%s%c, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, content, 34, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 34, 10, 34, content, 34, 10, 10, 34, 37, 37, 37, 34, 10, 10, 10, 10);%c	fflush(pointer);%c	sprintf(command, %cgcc -Wall -Wextra -Werror %cs -o %cs && ./%cs%c, filename, execname, execname);%c	system(command);%c	return (0);%c}%c";
	char filename[70];
	char execname[50];
	char command[300];
	sprintf(execname, "Sully_%d", i);
	sprintf(filename, "%s.c", execname);
	void *pointer = fopen(filename, "w");
	fprintf(pointer, "#include <stdlib.h>%c#include <stdio.h>%c%cint main()%c{%c	int i = %d;%c	if (i <= 0)%c		return (0);%c	i--;%c	char content[1000] = %c%s%c;%c	char filename[70];%c	char execname[50];%c	char command[300];%c	sprintf(execname, %cSully_%cd%c, i);%c	sprintf(filename, %c%cs.c%c, execname);%c	void *pointer = fopen(filename, %cw%c);%c	fprintf(pointer, %c%s%c, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, content, 34, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 34, 10, 34, content, 34, 10, 10, 34, 37, 37, 37, 34, 10, 10, 10, 10);%c	fflush(pointer);%c	sprintf(command, %cgcc -Wall -Wextra -Werror %cs -o %cs && ./%cs%c, filename, execname, execname);%c	system(command);%c	return (0);%c}%c", 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, content, 34, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 34, 10, 34, content, 34, 10, 10, 34, 37, 37, 37, 34, 10, 10, 10, 10);
	fflush(pointer);
	sprintf(command, "gcc -Wall -Wextra -Werror %s -o %s && ./%s", filename, execname, execname);
	system(command);
	return (0);
}
