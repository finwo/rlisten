# Find which C compilers are available
MGCC = $(shell command -v musl-gcc 2> /dev/null)
TCC  = $(shell command -v tcc 2> /dev/null)
GCC  = $(shell command -v gcc 2> /dev/null)

# Choose which to use
ifdef MGCC
	CC = musl-gcc
else ifdef TCC
	CC = tcc
else ifdef GCC
	CC = gcc
else
	shell echo "No C compiler found"
endif

CFLAGS  = -I. -Wall
DEPS = messages.h
OBJ  = rlisten.o messages.o
TARGET = rlisten

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	 for f in `find | grep -e \\\.o$$` ; do echo $$f ; rm $$f ; done

install:
	cp $(TARGET) /usr/local/bin/$(TARGET)
