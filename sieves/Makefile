CPPFLAGS=-Ofast -march=native -std=c++11
PREFIX=/usr/local

all: atkin.o sundaram.o eratosthenes.o billion.o
	g++ $(CPPFLAGS) atkin.o -o atkin
	g++ $(CPPFLAGS) sundaram.o -o sundaram
	g++ $(CPPFLAGS) eratosthenes.o -o eratosthenes
	g++ $(CPPFLAGS) billion.o -o billion

atkin.o: atkin.cpp

billion.o: billion.cpp

sundaram.o: sundaram.cpp

eratosthenes.o: eratosthenes.cpp

clean:
	rm -f *.o atkin eratosthenes sundaram billion

install: all
	install -m 0755 atkin eratosthenes sundaram $(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/{atkin, eratosthenes, sundaram}
