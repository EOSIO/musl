#include <math.h>
#include "libm.h"

int __signgam = 0;

#ifdef __APPLE__
int signgam = 0;
#else
weak_alias(__signgam, signgam);
#endif
