# Choose which compiler to use
CC = $(shell which musl-gcc tcc gcc | grep -v "not found" | head -n 1 || echo none)
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
