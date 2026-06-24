/* OS/400 MI IEEE floating-point configuration.

   The current port uses MI for floating-point support and keeps the
   libc view of the target strictly big-endian.  */

#ifndef __MACHINE_IEEEFP_H__
#define __MACHINE_IEEEFP_H__

#define __IEEE_BIG_ENDIAN

#ifndef __OBSOLETE_MATH_DEFAULT
#define __OBSOLETE_MATH_DEFAULT 1
#endif

#endif /* __MACHINE_IEEEFP_H__ */
