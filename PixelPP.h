#ifndef PIXELPP_H
#define PIXELPP_H

#define COLOR_MONO 0
#define COLOR_RGB 1
#define COLOR_RGBW 2

typedef uint8_t  colorType;

class PixelPP {

 public:

  // Constructor: number of LEDs, ColorType
  PixelPP(uint16_t n, colorType t=COLOR_RGB);
  ~PixelPP();

  void
    render(void)
}

#endif
