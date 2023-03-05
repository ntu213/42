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
printf("%d\n",		ft_printf("c/s/p/x/#X/+-d/ d/u/ u/%: %c / %+d / % d / %s / %p / %#x / %#X / %u / % u / %%\n", 'K', -213, 213, "OK", &i, 1023, 1024, 213, 213));
printf("%d\n",		   printf("c/s/p/x/#X/+-d/ d/u/ u/%: %c / %+d / % d / %s / %p / %#x / %#X / %u / % u / %%\n", 'K', -213, 213, "OK", &i, 1023, 1024, 213, 213));
//*/
}

/*

For /nfs/homes/vgiraudo/francinette/tests/printf/printfTester/tests/s_test.cpp:

36:     TEST(10, print(" NULL %s NULL ", NULL));

For /nfs/homes/vgiraudo/francinette/tests/printf/printfTester/tests/p_test.cpp:

33:     TEST(9, print(" %p %p ", 0, 0));

For /nfs/homes/vgiraudo/francinette/tests/printf/printfTester/tests/u_test.cpp:

25:     TEST(1, print(" %u ", 0));
49:     TEST(25, print(" %u ", LONG_MIN));
53:     TEST(29, print(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

For /nfs/homes/vgiraudo/francinette/tests/printf/printfTester/tests/x_test.cpp:

25:     TEST(1, print(" %x ", 0));
26:     TEST(2, print(" %x ", -1));
37:     TEST(13, print(" %x ", -9));
38:     TEST(14, print(" %x ", -10));
39:     TEST(15, print(" %x ", -11));
40:     TEST(16, print(" %x ", -14));
41:     TEST(17, print(" %x ", -15));
42:     TEST(18, print(" %x ", -16));

*/