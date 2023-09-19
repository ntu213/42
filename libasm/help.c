#include <stdlib.h>
#include <errno.h>

extern int *__errno_location();
extern void *malloc(size_t size);

int	*__errno_wrapper()
{
	return (__errno_location());
}

void* __malloc_wrapper(size_t size) {
    return malloc(size);
}
