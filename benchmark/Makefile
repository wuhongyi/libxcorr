all: compile

compile:
	gcc -ggdb -Werror -Wall -O3 benchmark.c -o benchmark -lxcorr

.PHONY: clean

clean:
	-rm -rf benchmark
