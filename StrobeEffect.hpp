#ifndef STROBEEFFECT_HPP
#define STROBEEFFECT_HPP
#include "common.h"
#include "rgb.h"
#include "PixelPP.hpp"
#include "Effect.hpp"

class StrobeEffect : public Effect
{
private:
    uint16_t _on;
    uint16_t _off;
    uint16_t _period;
public:
    StrobeEffect(PixelPP* parent, uint16_t on, uint16_t off);
    ~StrobeEffect();
    void render(unsigned long t);
};
#endif
