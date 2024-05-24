/* sincos -- currently no more efficient than two separate calls to
   sin and cos. */

#include "fdlibm.h"
#include <errno.h>

/* Disable sincos optimization for all functions in this file,
 * otherwise gcc would generate infinite calls.
 * Refer to gcc PR46926.
 * -fno-builtin-sin or -fno-builtin-cos can disable sincos optimization,
 * but these two options do not work inside optimize pragma in-file.
 * Thus we just enforce -O0 when compiling this file.
 */

#ifndef _DOUBLE_IS_32BITS

#ifdef __GNUC__
__attribute__((optimize("O0")))
#endif
#ifdef __STDC__
	void sincos(double x, double *sinx, double *cosx)
#else
	void sincos(x, sinx, cosx)
	double x;
        double *sinx;
        double *cosx;
#endif
{
  *sinx = sin (x);
  *cosx = cos (x);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
