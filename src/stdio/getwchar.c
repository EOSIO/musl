#include "stdio_impl.h"
#include <wchar.h>

wint_t getwchar(void)
{
	return fgetwc(stdin);
}

#ifdef __APPLE__
int getwchar_unlocked(void)
{
	return fgectwc(stdin);
}
#else
weak_alias(getwchar, getwchar_unlocked);
#endif
