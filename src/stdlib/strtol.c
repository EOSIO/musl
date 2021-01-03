#include "stdio_impl.h"
#include "intscan.h"
#include "shgetc.h"
#include <inttypes.h>
#include <limits.h>
#include <ctype.h>

static unsigned long long strtox(const char *s, char **p, int base, unsigned long long lim)
{
	FILE f;
	sh_fromstring(&f, s);
	shlim(&f, 0);
	unsigned long long y = __intscan(&f, base, 1, lim);
	if (p) {
		size_t cnt = shcnt(&f);
		*p = (char *)s + cnt;
	}
	return y;
}

unsigned long long strtoull(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, ULLONG_MAX);
}

unsigned long long strtoull_l(const char *nptr, char **endptr, size_t base, locale_t) {
	return strtoull(nptr, endptr, base);
}

long long strtoll(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, LLONG_MIN);
}

long long strtoll_l(const char *nptr, char **endptr, size_t base, locale_t) {
	return strtoll(nptr, endptr, base);
}

unsigned long strtoul(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, ULONG_MAX);
}

long strtol(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, 0UL+LONG_MIN);
}

intmax_t strtoimax(const char *restrict s, char **restrict p, int base)
{
	return strtoll(s, p, base);
}

uintmax_t strtoumax(const char *restrict s, char **restrict p, int base)
{
	return strtoull(s, p, base);
}

#ifdef __APPLE__
long __strtol_internal(const char *restrict s, char **restrict p, int base)
{
	return strtol(s,p,base);
}
unsigned long __strtoul_internal(const char *restrict s, char **restrict p, int base)
{
	return strtoul(s,p,base);
}
long long __strtoll_internal(const char *restrict s, char **restrict p, int base)
{
	return strtoll(s,p,base);
}
unsigned long long __strtoull_internal(const char *restrict s, char **restrict p, int base)
{
	return strtoull(s,p,base);
}
intmax_t __strtoimax_internal(const char *restrict s, char **restrict p, int base)
{
	return strtoll(s,p,base);
}
uintmax_t __strtoumax_internal(const char *restrict s, char **restrict p, int base)
{
	return strtoull(s,p,base);
}
#else
weak_alias(strtol, __strtol_internal);
weak_alias(strtoul, __strtoul_internal);
weak_alias(strtoll, __strtoll_internal);
weak_alias(strtoull, __strtoull_internal);
weak_alias(strtoimax, __strtoimax_internal);
weak_alias(strtoumax, __strtoumax_internal);
#endif
