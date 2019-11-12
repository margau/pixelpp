#ifndef SINEEFFECT_HPP
#define SINEEFFECT_HPP

#include "common.h"
#include "PixelPP.hpp"
#include "Effect.hpp"
#include "color_conv.hpp"

class SineEffect : public Effect
{
private:
    uint8_t _width;
    uint16_t _peri;
public:
    SineEffect(PixelPP* parent, uint8_t width, uint16_t period);
    ~SineEffect();
    void render(unsigned long t);
    void reset();
};

#endif
