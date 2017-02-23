#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "../include/xcorr.h"

void xcorr_timedomain(void *signala, void *signalb, void *result, int N)
{
	for (int tau = 0; tau < 2*N-1; ++tau) {
		complex acf = 0 + 0*I;
		for (int i = 0; i < N; ++i) {
			const int signala_idx = (i+tau)%(2*N-1);
			const complex conjb = conj(((complex*)signalb)[i]);
			const double factor = (signala_idx >= N) ?
				((complex*)signala)[signala_idx-N] : 1.0;
			acf += factor * conjb;
		}
		((complex*)result)[tau] = acf;
	}
	return;
}
