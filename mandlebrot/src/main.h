#ifndef MAIN_H
#define MAIN_H

typedef struct {
  int width;
  int height;
  double scale;
  double xoff, yoff;
  bool u_pallet;
  bool u_smooth;
  double m_iter;
  uint8_t monochrome[3];
  uint8_t **pallet;
} renderopt_t;
typedef renderopt_t mandlebrot_t;
typedef renderopt_t julia_t;

#define ESCAPE_TIME(x,y,i,it) (256 * \
    log2(1.75 + (i) - log2(log2(sqrt((x)*(x)+(y)*(y))))) / log2((double)it));

#endif
