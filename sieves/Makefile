CPPFLAGS=-Ofast -march=native -std=c++11
PREFIX=/usr/local

all: atkin.o eratosthenes.o
	g++ $(CPPFLAGS) atkin.o -o atkin
	g++ $(CPPFLAGS) eratosthenes.o -o eratosthenes

atkin.o: atkin.cpp

eratosthenes.o: eratosthenes.cpp

clean:
	rm -f *.o atkin eratosthenes

install: atkin
	install -m 0755 atkin eratosthenes $(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/{atkin, eratosthenes}
