CXX=g++
CXXFLAGS=-Ofast -march=native -Wall
PREFIX=/usr/local

all: clean atkin.o eratosthens.o
	$(CXX) atkin.o -o atkin
	$(CXX) eratosthenes.o -o eratosthenes

atkin.o: atkin.cpp
	$(CXX) $(CXXFLAGS) -c atkin.cpp -o atkin.o

eratosthens.o: eratosthenes.cpp
	$(CXX) $(CXXFLAGS) -c eratosthenes.cpp -o eratosthenes.o

clean:
	rm -f *.o atkin eratosthenes

install: atkin
	install -m 0755 atkin eratosthenes $(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/{atkin, eratosthenes}
