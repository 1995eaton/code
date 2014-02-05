CPPFLAGS=-Ofast -march=native
PREFIX=/usr/local

all: atkin.o eratosthenes.o
	g++ $(CPPFLAGS) atkin.o -o atkin
	g++ $(CPPFLAGS) eratosthenes.o -o eratosthenes

atkin_boost.o: atkin_boost.cpp

atkin.o: atkin.cpp

eratosthenes.o: eratosthenes.cpp

clean:
	rm -f *.o atkin atkin_boost eratosthenes

install: atkin
	install -m 0755 atkin eratosthenes $(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/{atkin, eratosthenes}
