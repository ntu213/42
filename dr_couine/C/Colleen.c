#include <unistd.h>
#include <stdio.h>

// Writing function
void ft_write()
{
	char str[] = "#include <unistd.h>%c#include <stdio.h>%c%c// Writing function%cvoid ft_write()%c{%c	char str[] = %c%s%c;%c	printf(%c%s%c, 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main()%c{%c	// The main function%c	ft_write();%c	return (0);%c}%c";
	printf("#include <unistd.h>%c#include <stdio.h>%c%c// Writing function%cvoid ft_write()%c{%c	char str[] = %c%s%c;%c	printf(%c%s%c, 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main()%c{%c	// The main function%c	ft_write();%c	return (0);%c}%c", 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main()
{
	// The main function
	ft_write();
	return (0);
}
