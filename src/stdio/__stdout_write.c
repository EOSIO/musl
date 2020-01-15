#include "stdio_impl.h"
//include <sys/ioctl.h>

extern void prints_l(char*, size_t);

size_t __stdout_write(FILE *f, const unsigned char *buf, size_t len)
{
   prints_l((char*)(f->wbase), f->wpos-f->wbase);
   prints_l((void*)buf, len);

   f->wend = f->buf + f->buf_size;
   f->wpos = f->wbase = f->buf;
   return f->wpos-f->wbase + len;
}
