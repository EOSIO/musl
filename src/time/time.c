#include <time.h>
//#include "syscall.h"

__attribute__((eosio_wasm_import))
extern uint64_t current_time();

time_t time(time_t *t)
{
	/*
		struct timespec ts;
	__clock_gettime(CLOCK_REALTIME, &ts);
	if (t) *t = ts.tv_sec;
	return ts.tv_sec;
	*/
	uint32_t elapsed = (uint32_t)(current_time() / 1000000ll);
	if (t) *t = elapsed;
	return elapsed;
}
