#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "sets.h"
#include "render.h"

const uint8_t monochrome[3] = { 255, 255, 255 };
const uint8_t pallet[][3] = {
    {66,  30,   15},
    {25,  7,    26},
    {9,   1,    47},
    {4,   4,    73},
    {0,   7,    100},
    {12,  44,   138},
    {24,  82,   177},
    {57,  125,  209},
    {134, 181,  229},
    {211, 236,  248},
    {241, 233,  191},
    {248, 201,  95},
    {255, 170,  0},
    {204, 128,  0},
    {153, 87,   0},
    {106, 52,   3}
};

void drawJulia(julia_t opt) {
  PNG png;
  create_png(&png, opt.width, opt.height, PNG_COLOR_TYPE_RGB);

  const double cre = -0.7;
  const double cim = 0.27015;

  for (int y = 0; y < opt.height; y++) {

    for (int x = 0; x < opt.width; x++) {

      double re = 1.5 * (x - opt.width / 2.0) / (0.5 * opt.scale * opt.width) + opt.xoff;
      double im = (y - opt.height / 2.0) / (0.5 * opt.scale * opt.height) + opt.yoff;
      int i = 0;

      for (double _re = 0; re*re + im*im < 4; i++) {
        _re = re*re - im*im + cre;
        im = 2 * re * im + cim;
        re = _re;
      }

      if (i < opt.m_iter) {

        const uint8_t *color = opt.u_pallet ? pallet[i % 16] : monochrome;

        if (opt.u_smooth) {
          int brightness = ESCAPE_TIME(re, im, i, opt.m_iter);
          set_color(&png, color[0] * brightness,
              color[1] * brightness,
              color[2] * brightness);
        } else {
          set_color(&png, color[0], color[1], color[2]);
        }

        put_pixel(&png, x, y);
      }

    }
  }
  write_png(&png, "output.png");

}

void drawMandlebrot(mandlebrot_t opt) {
  PNG png;
  create_png(&png, opt.width, opt.height, PNG_COLOR_TYPE_RGB);

  for (int y = 0; y < opt.height; y++) {

    for (int x = 0; x < opt.width; x++) {

      const double re = (x - opt.width / 2.0) / (0.5 * opt.scale * opt.width) + opt.xoff;
      const double im = (y - opt.height / 2.0) / (0.5 * opt.scale * opt.height) + opt.yoff;
      double rez = 0, imz = 0;
      int i = 0;

      for (double nrez = 0; rez*rez + imz*imz < 4 && i < opt.m_iter; i++) {
        nrez = rez*rez - imz*imz + re;
        imz = 2 * rez * imz + im;
        rez = nrez;
      }

      if (i < opt.m_iter) {

        const uint8_t *color = opt.u_pallet ? pallet[i % 16] : monochrome;

        if (opt.u_smooth) {
          int brightness = ESCAPE_TIME(rez, imz, i, opt.m_iter);
          set_color(&png, color[0] * brightness,
              color[1] * brightness,
              color[2] * brightness);
        } else {
          set_color(&png, color[0], color[1], color[2]);
        }

        put_pixel(&png, x, y);
      }

    }
  }
  write_png(&png, "output.png");
}

int main(void) {
  /* mandlebrot_t mopt = { */
  /*   1920, */
  /*   1080, */
  /*   0.85, */
  /*   -0.5, */
  /*   0, */
  /*   0, */
  /*   1, */
  /*   50 */
  /* }; */
  /* drawMandlebrot(mopt); */
  julia_t jopt = {
    1920,
    1080,
    0.85,
    0,
    0,
    1,
    0,
    150
  };
  drawJulia(jopt);
  return 0;
}
