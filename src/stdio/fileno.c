#include "stdio_impl.h"
#include <errno.h>

int fileno(FILE *f)
{
	FLOCK(f);
	int fd = f->fd;
	FUNLOCK(f);
	if (fd < 0) {
		errno = EBADF;
		return -1;
	}
	return fd;
}

#ifdef __APPLE__
int fileno_unlocked(FILE *f)
{
	return fileno(f);
}
#else
weak_alias(fileno, fileno_unlocked);
#endif
