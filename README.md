# libxcorr

Check out [the original README](./README.txt.orig).

This is a C and C++ compatible cross-correlation library.

### Build/install

Cmake project:

```
mkdir build && cd build
cmake ..
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

FFTW3 is a required dependency for the `xcorr_fftw` function. To compile without FFTW (and only use `xcorr_timedomain`), use the following CMake flag:

`cmake -DNO_FFTW=ON`

### Compatible with C and C++

Uses `void *` ptrs to avoid any C `_Complex*` and CPP `std::complex<double>` interop black magic.
