#!/usr/bin/env python3

from ctypes import *
xcorr_lib = cdll.LoadLibrary('/usr/local/lib/libxcorr.so')

class COMPLEX(Structure):
     _fields_ = [("real", c_double),
                 ("imag", c_double)]


if __name__ == '__main__':
    audio_buffer = [-1037.9783648981459,
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
                    4327.97278013234]

    size = 2*(len(audio_buffer)) - 1
    autocorr_complex = [COMPLEX(0.0, 0.0)] * size
    autocorr_complex_c = (COMPLEX * size)(*autocorr_complex)
    audio_buffer_c = (c_double * len(audio_buffer))(*audio_buffer)
    xcorr_lib.xcorr_fftw_r2c(audio_buffer_c, audio_buffer_c,
                             autocorr_complex_c,
                             len(audio_buffer))
    for i, x in enumerate(autocorr_complex):
        print('{}\t{}\t{}'.format(i, x.real, x.imag))
