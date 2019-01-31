#include "stdio_impl.h"
//include <sys/uio.h>

__attribute__((eosio_wasm_import))
extern void prints_l(const char*, size_t);
size_t __stdio_write(FILE *f, const unsigned char *buf, size_t len)
{
   prints_l((char*)(f->wbase), f->wpos-f->wbase);
   prints_l((void*)buf, len);
   return f->wpos-f->wbase + len;
}
