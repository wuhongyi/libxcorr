#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <xcorr.h>
#include <complex.h>

int main(int argc, char **argv)
{
	printf("Hello\n");

	srand((unsigned)time(NULL));

	int size = 8092*8;
	complex *signal_in = (complex *) malloc(size*sizeof(complex));
	complex *signal_out = (complex *) malloc(-1 + 2*size*sizeof(complex));

	for (int i = 0; i < size; ++i)
		signal_in[i] = ((double)rand()/(double)RAND_MAX) +
			I*((double)rand()/(double)RAND_MAX);

	xcorr_timedomain(signal_in, signal_in, signal_out, size);

	return 0;
}
