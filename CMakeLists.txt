project (libxcorr C)
cmake_minimum_required (VERSION 3.1)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Werror -Wall -O3 -std=c99 -fPIC -ffast-math")
set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# find third party modules
set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
find_package (FFTW)
# end find third party modules

# for testing time-domain xcorr by pretending FFTW is not installed
# set (FFTW_FOUND "False")

set (LIBS "m")
if (FFTW_FOUND)
  LIST (APPEND LIBS "fftw3")
  add_definitions (-DFFTW_ENABLED)
endif (FFTW_FOUND)

add_library (xcorr SHARED ${SRC_DIR}/fftw.c ${SRC_DIR}/timedomain.c ${SRC_DIR}/generic.c)
target_link_libraries (xcorr ${LIBS})
install (TARGETS xcorr DESTINATION /usr/local/lib)
install (FILES ${INCLUDE_DIR}/xcorr.h DESTINATION /usr/local/include)
