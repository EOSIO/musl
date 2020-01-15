#include "stdio_impl.h"
//include <sys/uio.h>

__attribute__((eosio_wasm_import)) int write_file(int fd, char* begin, char* end);

__attribute__((eosio_wasm_import)) void printi(long long);
__attribute__((eosio_wasm_import)) void prints_l(char*, int);

size_t __stdio_write(FILE *f, const unsigned char *buf, size_t len)
{
   write_file(f->fd, (char*)f->wbase, (char*)f->wpos);
   write_file(f->fd, (char*)buf, (char*)buf + len);

   f->wend = f->buf + f->buf_size;
   f->wpos = f->wbase = f->buf;
   return f->wpos-f->wbase + len;
}
