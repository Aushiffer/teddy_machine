CFLAGS = -g -Wall -Wextra -pedantic
PROGRAM = teddy_machine
CC = gcc
OBJS = main.o teddy_machine.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

teddy_machine.o: teddy_machine.c teddy_machine.h
	$(CC) -c teddy_machine.c $(CFLAGS)

clean:
	rm -rf *.gch *.o $(PROGRAM)
