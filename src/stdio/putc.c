#include <stdio.h>
#include "putc.h"

int putc(int c, FILE *f)
{
	return do_putc(c, f);
}

#ifdef __APPLE__
int _IO_putc(int c, FILE *f)
{
	return putc(c,f);
}
#else
weak_alias(putc, _IO_putc);
#endif
