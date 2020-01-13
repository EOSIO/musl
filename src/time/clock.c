#include <time.h>
#include <limits.h>

__attribute__((eosio_wasm_import)) int clock_gettime(clockid_t, struct timespec *);

clock_t clock()
{
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts))
		return -1;

	if (ts.tv_sec > LONG_MAX/1000000
	 || ts.tv_nsec/1000 > LONG_MAX-1000000*ts.tv_sec)
		return -1;

	return ts.tv_sec*1000000 + ts.tv_nsec/1000;
}
