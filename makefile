CFLAGS = -Wall -fsanitize=address

all: bataille_navale

bataille_navale: bataille_navale.o main.o
	gcc $(CFLAGS) -o bataille_navale bataille_navale.o main.o

bataille_navale.o: bataille_navale.c bataille_navale.h
	gcc $(CFLAGS) -c bataille_navale.c

main.o: main.c bataille_navale.h
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.o bataille_navale

