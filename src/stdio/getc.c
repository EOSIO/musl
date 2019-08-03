#include <stdio.h>
#include "getc.h"

int getc(FILE *f)
{
	return do_getc(f);
}

#ifdef __APPLE__
int _IO_getc(FILE *f)
{
	return getc(f);
}
#else
weak_alias(getc, _IO_getc);
#endif
