#ifndef SINEEFFECT_HPP
#define SINEEFFECT_HPP

#include "common.h"
#include "PixelPP.h"
#include "Effect.hpp"
#include "color_conv.hpp"

class SineEffect : public Effect
{
private:
    uint8_t _width;
public:
    SineEffect(PixelPP* parent, uint8_t width);
    ~SineEffect();
    void render(unsigned long t);
    void reset();
};

#endif
