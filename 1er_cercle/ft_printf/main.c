#include "ft_printf.h"

int	ft_printf(const char *origin, ...);

void	main(int argc, char ** argv)
{
	int	i = 1;

///*
	ft_printf("c:%c\n", 'K');
printf("c:%c\n", 'K');
	ft_printf(" c:% c\n", 'K');
printf(" c:% c\n", 'K');
	ft_printf("s:%s\n", "OK");
printf("s:%s\n", "OK");
	ft_printf(" s:% s\n", "OK");
printf(" s:% s\n", "OK");
	ft_printf("p:%p\n", &i);
printf("p:%p\n", &i);
	ft_printf("x:%x\n", 1023);
printf("x:%x\n", 1023);
	ft_printf("#x:%#x\n", 1024);
printf("#x:%#x\n", 1024);
	ft_printf("X:%X\n", 1023);
printf("X:%X\n", 1023);
	ft_printf("#X:%#X\n", 1024);
printf("#X:%#X\n", 1024);
	ft_printf("d:%d\n", 213);
printf("d:%d\n", 213);
	ft_printf("+d:%+d\n", 213);
printf("+d:%+d\n", 213);
	ft_printf("+-d:%+d\n", -213);
printf("+-d:%+d\n", -213);
	ft_printf("-d:%d\n", -213);
printf("-d:%d\n", -213);
	ft_printf(" -d:% d\n", -213);
printf(" -d:% d\n", -213);
	ft_printf(" +d:% +d\n", 213);
printf(" +d:% +d\n", 213);
	ft_printf(" d:% d\n", 213);
printf(" d:% d\n", 213);
	ft_printf("%:%%\n", 213);
printf("%:%%\n", 213);
//*/

ft_printf("\n		//// BUGGED \\\\\\\\\n\n");

	printf("%d\n", ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
printf("%d\n", printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

ft_printf("\n\n");

//*
printf("%d\n",	 ft_printf("c/s/p/x/#X/+-d/ d/u/ u/%: %c / %+d / % d / %s / %p / %#x / %#X / %u / % u / %%\n", 'k', -213, 213, "OK", &i, 1023, 1024, 213, 213));
printf("%d\n",		printf("c/s/p/x/#X/+-d/ d/u/ u/%: %c / %+d / % d / %s / %p / %#x / %#X / %u / % u / %%\n", 'K', -213, 213, "OK", &i, 1023, 1024, 213, 213));
//*/
}
