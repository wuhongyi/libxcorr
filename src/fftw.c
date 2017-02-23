#include "../include/xcorr.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>

void xcorr_fftw(void *signala, void *signalb, void *result, int N)
{
	int N2 = 2 * N - 1;

	complex * signala_ext = (complex *) calloc(N2, sizeof(complex));
	complex * signalb_ext = (complex *) calloc(N2, sizeof(complex));

	// zero padding
	memcpy(signala_ext + (N - 1), signala, sizeof(complex) * N);
	memcpy(signalb_ext, signalb, sizeof(complex) * N);

	fftw_complex * outa = fftw_alloc_complex(N2);
	fftw_complex * outb = fftw_alloc_complex(N2);
	fftw_complex * out = fftw_alloc_complex(N2);

	fftw_plan pa = fftw_plan_dft_1d(N2, signala_ext, outa, FFTW_FORWARD,
					FFTW_ESTIMATE);
	fftw_plan pb = fftw_plan_dft_1d(N2, signalb_ext, outb, FFTW_FORWARD,
					FFTW_ESTIMATE);
	fftw_plan px = fftw_plan_dft_1d(N2, out, result, FFTW_BACKWARD,
					FFTW_ESTIMATE);

	fftw_execute(pa);
	fftw_execute(pb);

	fftw_complex scale = 1.0/(2 * N -1);
	for (int i = 0; i < N2; ++i)
		out[i] = outa[i] * conj(outb[i]) * scale;

	fftw_execute(px);

	fftw_destroy_plan(pa);
	fftw_destroy_plan(pb);
	fftw_destroy_plan(px);

	fftw_free(out);
	fftw_free(outa);
	fftw_free(outb);

	fftw_cleanup();

	free(signala_ext);
	free(signalb_ext);
	return;
}

void xcorr_fftw_r2c(void *signala, void *signalb, void *result,
		    int N)
{
	int N2 = 2 * N - 1;

	double * signala_ext = (double *) calloc(N2, sizeof(double));
	double * signalb_ext = (double *) calloc(N2, sizeof(double));

	// zero padding
	memcpy(signala_ext + (N - 1), signala, sizeof(double) * N);
	memcpy(signalb_ext, signalb, sizeof(double) * N);

	complex * outa = fftw_alloc_complex(N2);
	complex * outb = fftw_alloc_complex(N2);
	fftw_complex * out = fftw_alloc_complex(N2);

	fftw_plan pa = fftw_plan_dft_r2c_1d(N2, signala_ext, outa,
					    FFTW_FORWARD | FFTW_ESTIMATE);
	fftw_plan pb = fftw_plan_dft_r2c_1d(N2, signalb_ext, outb,
					    FFTW_FORWARD | FFTW_ESTIMATE);
	fftw_plan px = fftw_plan_dft_1d(N2, out, result, FFTW_BACKWARD,
					FFTW_ESTIMATE);

	fftw_execute(pa);
	fftw_execute(pb);

	fftw_complex scale = 1.0/(2 * N -1);
	for (int i = 0; i < N2; ++i)
		out[i] = outa[i] * conj(outb[i]) * scale;

	fftw_execute(px);

	fftw_destroy_plan(pa);
	fftw_destroy_plan(pb);
	fftw_destroy_plan(px);

	fftw_free(out);
	fftw_free(outa);
	fftw_free(outb);

	fftw_cleanup();

	free(signala_ext);
	free(signalb_ext);
	return;
}
