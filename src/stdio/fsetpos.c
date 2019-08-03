#include "stdio_impl.h"

int fsetpos(FILE *f, const fpos_t *pos)
{
	return __fseeko(f, *(const long long *)pos, SEEK_SET);
}

#ifdef __APPLE__
int fsetpos64(FILE *f, const fpos_t *pos)
{
	return fsetpos(f,pos);
}
#else
weak_alias(fsetpos, fsetpos64);
#endif
