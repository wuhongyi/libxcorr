# libxcorr

Check out [the original README](./README.txt.orig).

This is a C and C++ compatible cross-correlation library.

### Build/install

Cmake project:

```
mkdir build
cd build && cmake ..
make
sudo make install
```

This installs `xcorr.h` into `/usr/local/include`, and `libxcorr.so` into `/usr/local/lib`. Use `-lxcorr` to link against it.

To use in C, use `#include <xcorr.h>`. To use in C++:

```
extern "C" {
#include <xcorr.h>
}
```

### Dependencies

FFTW3 is a required dependency. TODO is to pass a compiler flag to compile without FFTW3, to explicitly use the time-domain xcorr function.

### Compatible with C and C++

Originally I did convoluted things with `ifdef __cplusplus` in an `inline` function in `xcorr.h` to cast from `std::complex<double>` to `_Complex`, but now I avoid all of that by just using `void *` ptrs.
