project (libxcorr C)
cmake_minimum_required (VERSION 3.1)

option(NO_FFTW "NO_FFTW" OFF)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Werror -Wall -O3 -std=c99 -fPIC -ffast-math")
set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set (LIB_LIST "${SRC_DIR}/timedomain.c")

if (NOT NO_FFTW)
    LIST (APPEND LIB_LIST "${SRC_DIR}/fftw.c")
endif (NOT NO_FFTW)

add_library (xcorr SHARED ${LIB_LIST})
target_link_libraries (xcorr m fftw3)
install (TARGETS xcorr DESTINATION /usr/local/lib)
install (FILES ${INCLUDE_DIR}/xcorr.h DESTINATION /usr/local/include)
