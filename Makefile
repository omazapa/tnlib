CC = gcc
LIBFLAGS = -shared -Iinclude  -fPIC 
CFLAGS = -Iinclude 
LDFLAGS = -L. -lNumberTheory
all: src/NumberTheory.c include/NumberTheory.h
	$(CC) $(LIBFLAGS) src/NumberTheory.c -o libNumberTheory.so
	$(CC) $(CFLAGS) src/NumberTheory.c tests/tests.c -o test
