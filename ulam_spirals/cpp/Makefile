CPPFLAGS=-Wall -Ofast -I/usr/include/SDL -std=c++11
LDFLAGS=-lSDL -lSDL_gfx

ulam: ulam.o
	g++ $(LDFLAGS) $(CPPFLAGS) -o ulam ulam.o

ulam.o: ulam.cpp

clean:
	rm -f ulam.o ulam
