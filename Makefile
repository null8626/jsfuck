CC=gcc
AR=ar

EXTRA_CFLAGS=
CFLAGS=-O3 -Wall -m64 -I include

ifeq ($(WIN),yes)
TRANSPILER=jsfuck.exe
else
TRANSPILER=jsfuck
endif

ifeq ($(CC),clang)
AR=llvm-ar
endif

ifeq ($(SHARED),yes)
LIB=libjsfuck.so
_EXTRA_LIB_CFLAGS=$(LIB) -Wl,-rpath=.
else
LIB=libjsfuck.a
_EXTRA_LIB_CFLAGS=-L. -ljsfuck
endif

$(TRANSPILER): $(LIB) src/transpiler/transpiler.c src/transpiler/io.c
	$(CC) $(CFLAGS) src/transpiler/transpiler.c src/transpiler/io.c -o $(TRANSPILER) $(_EXTRA_LIB_CFLAGS)

libjsfuck.so: jsfuck.o stream.o token.o common.o
	$(CC) -shared -o $@ $^

libjsfuck.a: jsfuck.o stream.o token.o common.o
	$(AR) rcs -o $@ $^

jsfuck.o: src/jsfuck.c
	$(CC) $(CFLAGS) -c $< -o $@

stream.o: src/stream.c
	$(CC) $(CFLAGS) -c $< -o $@

token.o: src/token.c
	$(CC) $(CFLAGS) -c $< -o $@

common.o: src/common.c
	$(CC) $(CFLAGS) -c $< -o $@