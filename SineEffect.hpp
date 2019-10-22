#ifndef SINEEFFECT_HPP
#define SINEEFFECT_HPP

#include "common.h"
#include "PixelPP.h"
#include "Effect.hpp"

class SineEffect : Effect
{
private:
    uint8_t _width;
    uint8_t _step;
public:
    SineEffect(PixelPP* parent, uint8_t width);
    ~SineEffect();
    void render();
    void reset();
};

#endif
