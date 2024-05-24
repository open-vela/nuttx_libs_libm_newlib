/* sincos -- currently no more efficient than two separate calls to
   sin and cos. */
#include "fdlibm.h"
#if __OBSOLETE_MATH

/* Disable sincos optimization for all functions in this file,
 * otherwise gcc would generate infinite calls.
 * Refer to gcc PR46926.
 * -fno-builtin-sin or -fno-builtin-cos can disable sincos optimization,
 * but these two options do not work inside optimize pragma in-file.
 * Thus we just enforce -O0 when compiling this file.
 */

#include <errno.h>

#ifdef __GNUC__
__attribute__((optimize("O0")))
#endif
#ifdef __STDC__
	void sincosf(float x, float *sinx, float *cosx)
#else
	void sincosf(x, sinx, cosx)
	float x;
        float *sinx;
        float *cosx;
#endif
{
  *sinx = sinf (x);
  *cosx = cosf (x);
}

#ifdef _DOUBLE_IS_32BITS

#ifdef __GNUC__
__attribute__((optimize("O0")))
#endif
#ifdef __STDC__
	void sincos(double x, double *sinx, double *cosx)
#else
	void sincos(x, sinx, cosx)
	double x;
        double sinx;
        double cosx;
#endif
{
  *sinx = sinf((float) x);
  *cosx = cosf((float) x);
}
#endif /* defined(_DOUBLE_IS_32BITS) */
#endif /* __OBSOLETE_MATH */
