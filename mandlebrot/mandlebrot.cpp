#include "SDL.h" 
#include <cmath>
#include <iostream>

const double size = 1;
const double x_offset = 0;
const double y_offset = 0;
const bool smooth = 1;
const bool use_pallet = 0;
const int iterations = 100;
const int WIDTH = 1920*3;
const int HEIGHT = 1080*3;
const ulong AREA = WIDTH*HEIGHT;

using namespace std;


void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel) { 
  int bpp = surface->format->BytesPerPixel; 
  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp; 

        p[0] = pixel & 0xff; 
        p[1] = (pixel >> 8) & 0xff; 
        p[2] = (pixel >> 16) & 0xff; 
} 

void drawMandlebrot(SDL_Surface *surface) {
  int monochrome[3] = {255, 255, 255};
  int pallet[16][3] {
    {66, 30, 15},
      {25, 7, 26},
      {9, 1, 47},
      {4, 4, 73},
      {0, 7, 100},
      {12, 44, 138},
      {24, 82, 177},
      {57, 125, 209},
      {134, 181, 229},
      {211, 236, 248},
      {241, 233, 191},
      {248, 201, 95},
      {255, 170, 0},
      {204, 128, 0},
      {153, 87, 0},
      {106, 52, 3}
  };
  double x0, y0;
  double xtemp, x, ytemp, y;
  Uint32 color;
  for (int pY = 0; pY < HEIGHT; pY++) {
    for (int pX = 0; pX < WIDTH; pX++) {
      x0 = 1.5*(pX - WIDTH/2) / (0.5 * size * WIDTH) + x_offset;
      y0 = (pY - HEIGHT/2) / (0.5 * size * HEIGHT) + y_offset;
      xtemp=x=ytemp=y=0;
      int i = 0;

      while (x*x + y*y < 4 && i < iterations) {
        xtemp = x*x - y*y + x0;
        ytemp = 2*x*y + y0;
        if (x == xtemp && y == ytemp) {
          i = iterations; break;
        }
        x = xtemp; y = ytemp;
        i++;
      }
      if (i < iterations) {
        int brightness = 256 * log2(1.75 + i - log2(log2(sqrt(x*x+y*y)))) / log2(double(iterations));
        int *p = pallet[i%16];
        if (smooth) {
          if (use_pallet) {
            color = SDL_MapRGB(surface->format, brightness*p[0], brightness*p[1], brightness*p[2]);
          } else {
            color = SDL_MapRGB(surface->format,
                brightness*monochrome[0],
                brightness*monochrome[1],
                brightness*monochrome[2]);
          }
        } else {
          if (use_pallet) {
            color = SDL_MapRGB(surface->format, p[0], p[1], p[2]);
          } else {
            color = SDL_MapRGB(surface->format, monochrome[0], monochrome[1], monochrome[2]);
          }
        }
        putpixel(surface, pX, pY, color);
      }
    }
  }
  SDL_UpdateRect(surface, 0, 0, 0, 0);
}

int main(int argc, char *argv[]) { 
  SDL_Surface *screen = SDL_SetVideoMode(WIDTH, HEIGHT, 24, SDL_SWSURFACE); 
  SDL_Event event; 
  int x, y; 
  bool isRunning;

  if (SDL_MUSTLOCK(screen)) {SDL_UnlockSurface(screen);} 
  drawMandlebrot(screen);
  SDL_SaveBMP(screen, "out.bmp");
  isRunning = true;
  while (isRunning) { 
    while (SDL_PollEvent(&event)) { 
      switch (event.type) { 
        case SDL_KEYUP: 
          if(event.key.keysym.sym == SDLK_ESCAPE) 
            isRunning = false; break; 
        case SDL_QUIT: 
          isRunning = false; break; 
        default: 
          break; 
      } 
    } 
    SDL_Delay(10);
  } 
  SDL_Quit(); 
  return 0; 
} 
