project (libxcorr C)
cmake_minimum_required (VERSION 3.1)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Werror -Wall -O3 -std=c99 -fPIC -ffast-math")
set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# find third party modules
set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
find_package (FFTW REQUIRED)
# end find third party modules

add_library (xcorr SHARED ${SRC_DIR}/fftw.c ${SRC_DIR}/timedomain.c)
target_link_libraries (xcorr m fftw3)
install (TARGETS xcorr DESTINATION /usr/local/lib)
install (FILES ${INCLUDE_DIR}/xcorr.h DESTINATION /usr/local/include)
