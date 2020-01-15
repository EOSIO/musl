#include "stdio_impl.h"
//include <sys/uio.h>

__attribute__((eosio_wasm_import)) int read_file(int fd, char* begin, char* end);

size_t __stdio_read(FILE *f, unsigned char *buf, size_t len)
{
       ssize_t cnt0, cnt1, cnt;
       ssize_t buflen = len - !!f->buf_size;

       cnt0 = read_file(f->fd, buf, buf + buflen );
       if(cnt0 < 0) {
          cnt = cnt0;
       } else {
          cnt1 = read_file(f->fd, f->buf, f->buf + f->buf_size);
          if(cnt1 < 0) cnt = cnt1;
          else cnt = cnt0 + cnt1;
       }
       if (cnt < 0) {
               f->flags |= F_EOF ^ ((F_ERR^F_EOF) & cnt);
               return cnt;
       }
       if (cnt <= buflen) return cnt;
       cnt -= buflen;
       f->rpos = f->buf;
       f->rend = f->buf + cnt;
       if (f->buf_size) buf[len-1] = *f->rpos++;
       return len;
}
