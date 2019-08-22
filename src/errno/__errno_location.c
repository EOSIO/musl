#include <errno.h>
#include "pthread_impl.h"

int *__errno_location(void)
{
	return &__pthread_self()->errno_val;
}

#ifdef __APPLE__
int * weak ___errno_location(void)
{
	return __errno_location();
}
#else
weak_alias(__errno_location, ___errno_location);
#endif
