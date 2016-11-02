CC = gcc
CFLAGS  = -I. -Wall
DEPS = messages.h
OBJ  = rlisten.o messages.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rlisten: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
