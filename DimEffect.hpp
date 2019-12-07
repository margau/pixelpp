#ifndef DIMEFFECT_HPP
#define DIMEFFECT_HPP
#include "common.h"
#include "rgb.h"
#include "PixelPP.hpp"
#include "Effect.hpp"

class DimEffect : public Effect
{
private:
    uint8_t _percentage; // 0 = no dimming, 255 = full dimming
public:
    DimEffect(PixelPP* parent, uint8_t percentage);
    ~DimEffect();
    void render(unsigned long t);
};
#endif
