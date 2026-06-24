/*
 * OS400MI build-only syscall stubs.
 *
 * This target exists to let newlib compile and link far enough to expose
 * missing OS/400 MI runtime support. Every entry point fails explicitly.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <stddef.h>
#include <reent.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>

#undef errno
extern int errno;

static int
os400mi_stub_int(void)
{
  errno = ENOSYS;
  return -1;
}

static _ssize_t
os400mi_stub_ssize(void)
{
  errno = ENOSYS;
  return -1;
}

static void *
os400mi_stub_ptr(void)
{
  errno = ENOSYS;
  return (void *) -1;
}

int
_close(int fildes)
{
  (void) fildes;
  return os400mi_stub_int();
}

int
_execve(const char *name, char *const *argv, char *const *env)
{
  (void) name;
  (void) argv;
  (void) env;
  return os400mi_stub_int();
}

int
_fstat(int fildes, struct stat *buf)
{
  (void) fildes;
  (void) buf;
  return os400mi_stub_int();
}

int
_getpid(void)
{
  return os400mi_stub_int();
}

int
_gettimeofday(struct timeval *tp, void *tzp)
{
  (void) tp;
  (void) tzp;
  return os400mi_stub_int();
}

int
_isatty(int fildes)
{
  (void) fildes;
  return 0;
}

int
_kill(int pid, int sig)
{
  (void) pid;
  (void) sig;
  return os400mi_stub_int();
}

int
_link(const char *existing, const char *newlink)
{
  (void) existing;
  (void) newlink;
  return os400mi_stub_int();
}

_off_t
_lseek(int fildes, _off_t ptr, int dir)
{
  (void) fildes;
  (void) ptr;
  (void) dir;
  return (_off_t) os400mi_stub_int();
}

int
_open(const char *file, int flags, int mode)
{
  (void) file;
  (void) flags;
  (void) mode;
  return os400mi_stub_int();
}

_ssize_t
_read(int file, void *ptr, size_t len)
{
  (void) file;
  (void) ptr;
  (void) len;
  return os400mi_stub_ssize();
}

int
_stat(const char *path, struct stat *buf)
{
  (void) path;
  (void) buf;
  return os400mi_stub_int();
}

clock_t
_times(struct tms *buf)
{
  (void) buf;
  return (clock_t) os400mi_stub_int();
}

int
_unlink(const char *path)
{
  (void) path;
  return os400mi_stub_int();
}

void *
_sbrk(ptrdiff_t incr)
{
  (void) incr;
  return os400mi_stub_ptr();
}

_ssize_t
_write(int file, const void *ptr, size_t len)
{
  (void) file;
  (void) ptr;
  (void) len;
  return os400mi_stub_ssize();
}

void
_exit(int code)
{
  (void) code;
  for (;;)
    ;
}
