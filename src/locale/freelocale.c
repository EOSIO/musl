#include <stdlib.h>
#include "locale_impl.h"

void freelocale(locale_t l)
{
	if (__loc_is_allocated(l)) free(l);
}

#ifdef __APPLE__
void __freelocale(locale_t l)
{
	return freelocale(l);
}
#else
weak_alias(freelocale, __freelocale);
#endif
