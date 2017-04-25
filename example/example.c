#include <stdio.h>
#include <xcorr.h>
#include <complex.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	double arr[12] = {
		-1037.9783648981459,
		-926.3002408107986,
		745.3304277435936,
		-1245.004719568383,
		1229.8104183815599,
		-1019.6116333494275,
		-43.911928116212266,
		-1317.8256649409036,
		-654.0575206918184,
		281.62894680563,
		-340.0525006874325,
		4327.97278013234
	};

	complex * result = malloc(23 * sizeof(complex));

	xcorr_fftw_r2c(arr, arr, result, 12);

	for (int x = 0; x < 23; ++x) {
		printf("%d\t%f\t%f\n", x, creal(result[x]), cimag(result[x]));
	}
}
