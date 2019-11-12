#ifndef PixEFFECT_HPP
#define PixEFFECT_HPP
#include "common.h"
#include "rgb.h"
#include "PixelPP.hpp"
#include "Effect.hpp"

struct pixfade {
  uint16_t n;
  unsigned long end;
};

class PixEffect : public Effect
{
private:
    rgb _color;
    std::vector<pixfade> pixfadeVector;
    uint16_t _length;
    uint8_t _num;
public:
    PixEffect(PixelPP* parent, rgb color, uint16_t length, uint8_t num);
    ~PixEffect();
    void render(unsigned long t);
};
#endif
