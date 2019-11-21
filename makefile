CC=gcc
FLAGS= -Wall -g

all: mybanks mybankd mains maind
mains: main.o
	$(CC) $(FLAGS) -o mains main.o libmyBank.a
maind: main.o libmyBank.a
	$(CC) $(FLAGS) -o maind main.o ./libmyBank.so
libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o	
mybanks: libmyBank.a
mybankd: libmyBank.so
libmyBank.so: myBank.o
	$(CC) -shared -o libmyBank.so myBank.o
main.o: main.c
	$(CC) $(FLAGS) -fPIC -c main.c
myBank.o: myBank.c
	$(CC) $(FLAGS) -fPIC -c myBank.c
.PHONY: clean all mybanks mybankd
make clean:
	rm -f *.o *.so *.a mains maind
