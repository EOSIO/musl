#include <unistd.h>
//#include "syscall.h"

off_t __lseek(int fd, off_t offset, int whence)
{
	/*
#ifdef SYS__llseek
	off_t result;
	return syscall(SYS__llseek, fd, offset>>32, offset, &result, whence) ? -1 : result;
#else
	return syscall(SYS_lseek, fd, offset, whence);
#endif
	*/
	return -1;
}

#ifdef __APPLE__
off_t weak lseek(int fc, off_t offset, int whence)
{
	return __lseek(fc, offset, whence);
}
off_t weak lseek64(int fc, off_t offset, int whence)
{
	return __lseek(fc, offset, whence);
}
#else
weak_alias(__lseek, lseek);
weak_alias(__lseek, lseek64);
#endif
