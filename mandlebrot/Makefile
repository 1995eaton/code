CPPFLAGS=-Ofast -I/usr/include/SDL -std=c++11
LDFLAGS=-lSDL -lSDL_gfx

mandlebrot: mandlebrot.o
	g++ $(LDFLAGS) $(CPPFLAGS) -o mandlebrot mandlebrot.o

mandlebrot.o: mandlebrot.cpp

clean:
	rm -f mandlebrot.o mandlebrot

install: mandlebrot
	cp mandlebrot /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/mandlebrot
