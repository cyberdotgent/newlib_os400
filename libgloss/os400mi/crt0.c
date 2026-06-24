/*
 * Minimal OS400MI hosted startup.
 *
 * The backend emits the OS/400 program entry wrapper and calls this _start
 * function when crt0.o is linked.  Real process setup and exit handling are
 * intentionally deferred until the backend can lower the needed libc paths.
 */

extern int main(void);

int
_start(void)
{
  int status;

  __builtin_os400mi_runtime_startup();
  status = main();
  return __builtin_os400mi_runtime_terminate(status);
}
