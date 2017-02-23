#include "../include/xcorr.h"

void xcorr(void *signala, void *signalb, void *result, int N)
{
#ifdef FFTW_ENABLED
	return xcorr_fftw(signala, signalb, result, N);
#else
	return xcorr_timedomain(signala, signalb, result, N);
#endif /* FFTW_ENABLED */
}
