#include "stdio_impl.h"
#include <string.h>
#include <errno.h>

__attribute__((eosio_wasm_import)) int open_file(const char* pathname, const char* pathname_end, const char* mode, const char* mode_end);
__attribute__((eosio_wasm_import)) void close_file(int fd);

FILE *fopen(const char *restrict filename, const char *restrict mode)
{
	FILE *f;
	int fd;
	int flags;

	/* Check for valid initial mode character */
	if (!strchr("rwa", *mode)) {
		errno = EINVAL;
		return 0;
	}

	/* Compute the flags to pass to open() */
	//flags = __fmodeflags(mode);

	fd = open_file(filename, filename+strlen(filename), mode, mode+strlen(mode));
	if (fd < 0) return 0;

	f = __fdopen(fd, mode);
	if (f) return f;

	close_file(fd);
	return 0;
}
