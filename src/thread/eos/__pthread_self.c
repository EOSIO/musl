#include "locale_impl.h"
#include "pthread_impl.h"

struct pthread *__pthread_self()
{
   static struct pthread self = { 0 , UTF8_LOCALE};
   return &self;
}