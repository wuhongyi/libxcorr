#ifndef XCORR_H
#define XCORR_H

void xcorr(void *signala, void *signalb, void *result, int N);

void xcorr_fftw(void *signala, void *signalb, void *result, int N);

void xcorr_timedomain(void *signala, void *signalb, void *result, int N);

#endif /* XCORR_H */
