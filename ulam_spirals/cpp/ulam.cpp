#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include "SDL.h"


void putpixel (SDL_Surface *surface, int x, int y, Uint32 pixel);
void fillSieve (std::vector<bool> &sieve);
void putSpiral (SDL_Surface*& screen, std::vector<bool> &sieve, Uint32 &color);

int SIDE;
ulong LIMIT;

int main(int argc, char** argv) {

  Uint32 color;
  SDL_Surface *screen;
  if (argc == 1) {
    std::cerr << "Error: enter a side length\n";
    return 0;
  }
  std::istringstream iss(argv[1]);
  if (!(iss >> SIDE)) {
    std::cerr << "Error: '" << argv[1] << "' positive integer required\n";
    return 0;
  }

  LIMIT = SIDE*SIDE;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
    exit(1);
  }

  atexit(SDL_Quit);
  screen = SDL_SetVideoMode(SIDE, SIDE, 8, SDL_SWSURFACE | SDL_ANYFORMAT);

  if (screen == NULL) {
    std::cout << "Error setting video mode: " << SDL_GetError() << std::endl;
  }

  SDL_Event event;

  if (SDL_MUSTLOCK(screen)) {
    if (SDL_LockSurface(screen) < 0) {
      std::cout << "Error locking screen: " << SDL_GetError() << std::endl;
      return 0;
    }
  }
  color = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);

  if (SDL_MUSTLOCK(screen)) {
    SDL_UnlockSurface(screen);
  }
  
  std::vector<bool> sieve(LIMIT, 0);
  fillSieve(sieve);
  putSpiral(screen, sieve, color);

  bool isRunning = 1;
  while (isRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        isRunning = 0;
      }
    }
    SDL_Delay(32);
  }

  char* filename = strcat(argv[1], ".png");
  SDL_SaveBMP(screen, filename);
  SDL_FreeSurface(screen);
  return 0;
}

void putpixel (SDL_Surface *surface, int x, int y, Uint32 pixel) {
  int bpp = surface->format->BytesPerPixel;

  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

  switch(bpp) {
    case 1:
      *p = pixel;
      break;

    case 2:
      *(Uint16 *)p = pixel;
      break;

    case 3:
      if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        p[0] = (pixel >> 16) & 0xff;
        p[1] = (pixel >> 8) & 0xff;
        p[2] = pixel & 0xff;
      } else {
        p[0] = pixel & 0xff;
        p[1] = (pixel >> 8) & 0xff;
        p[2] = (pixel >> 16) & 0xff;
      }
      break;

    case 4:
      *(Uint32 *)p = pixel;
      break;
  }
}

void putSpiral(SDL_Surface*& screen, std::vector<bool> &sieve, Uint32 &color) {
  int c = 2, i = 1;
  int x, y, n;

  x = (int) ((SIDE+1)/2); y = x-1;
  putpixel(screen, x, y, color);
  SDL_UpdateRect(screen, x, y, 1, 1);

  for (int len = 0; len < (int) ((SIDE-1)/2); len++) {
    for (n = 0; n < i; n++) {
      y--; c++;
      if (sieve[c]) {
        putpixel(screen, x, y, color);
        SDL_UpdateRect(screen, x, y, 1, 1);
      }
    } i++;
    for (n = 0; n < i; n++) {
      x--; c++;
      if (sieve[c]) {
        putpixel(screen, x, y, color);
        SDL_UpdateRect(screen, x, y, 1, 1);
      }
    }
    for (n = 0; n < i; n++) {
      y++; c++;
      if (sieve[c]) {
        putpixel(screen, x, y, color);
        SDL_UpdateRect(screen, x, y, 1, 1);
      }
    } i++;
    for (n = 0; n < i; n++) {
      x++; c++;
      if (sieve[c]) {
        putpixel(screen, x, y, color);
        SDL_UpdateRect(screen, x, y, 1, 1);
      }
    }
  }
}

void fillSieve (std::vector<bool> &sieve) {
  sieve[2] = 1; sieve[3] = 1;
  for(int x = 1; x < SIDE; x++) {
    for(int y = 1; y < SIDE; y++) {
      ulong n = 4*x*x+y*y;
      if (n <= LIMIT && (n % 12 == 1 || n % 12 == 5)) {
        sieve[n] = !sieve[n];
      }
      n = 3*x*x+y*y;
      if (n <= LIMIT && n % 12 == 7) {
        sieve[n] = !sieve[n];
      }
      n = 3*x*x-y*y;
      if (x > y && n <= LIMIT && n % 12 == 11) {
        sieve[n] = !sieve[n];
      }
    }
  }
  for(int n = 5; n < SIDE; n++) {
    if(sieve[n]) {
      ulong nn = n*n;
      for(ulong i = nn; i < LIMIT; i += nn) {
        sieve[i] = 0;
      }
    }
  }
}
