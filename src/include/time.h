#ifndef TIME_H
#define TIME_H

#include "../../include/time.h"

//hidden int __clock_gettime(clockid_t, struct timespec *);

hidden char *__asctime_r(const struct tm *, char *);
hidden struct tm *__gmtime_r(const time_t *, struct tm *);
//hidden struct tm *__localtime_r(const time_t *restrict, struct tm *restrict);

hidden size_t __strftime_l(char *, size_t, const char *, const struct tm *, locale_t);

#endif
