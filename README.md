# libxcorr

Please see the end of this file for the original fork's README.

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

FFTW3 is an optional dependency.

If you don't have FFTW3, `xcorr_fftw` is unavailable and `xcorr` calls `xcorr_timedomain`. Otherwise, `xcorr` calls `xcorr_fftw`.

### Compatible with C and C++

Originally I did convoluted things with `ifdef __cplusplus` in an `inline` function in `xcorr.h` to cast from `std::complex<double>` to `_Complex`, but now I avoid all of that by just using `void *` ptrs.

# Original README

libxcorr
========

Library that provides a Cross Correlation function for C
based on FFTW3.

=====================================================================
I. Dependencies

- fftw3

---------------------------------------------------------------------
II. Build Instructions

- make libxcorr
- sudo make install

Or

- sudo make all

You will probably need to create these dirs:

- /usr/local/lib
- /usr/local/include

---------------------------------------------------------------------
III. License

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

---------------------------------------------------------------------
IV. Author

David E. Narváez
dMaggot
david.narvaez@computer.org
