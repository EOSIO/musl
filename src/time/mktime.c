#include "time_impl.h"
#include <errno.h>

time_t mktime(struct tm *tm)
{
   struct tm new;
   long opp;
   long long t = __tm_to_secs(tm);

   return t;
}