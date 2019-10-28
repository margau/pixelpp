#ifndef FILLEFFECT_HPP
#define FILLEFFECT_HPP
#include "common.h"
#include "rgb.h"
#include "PixelPP.h"
#include "Effect.hpp"

class FillEffect : public Effect
{
private:
    rgb _color;
public:
    FillEffect(PixelPP* parent, rgb color);
    ~FillEffect();
    void render(unsigned long t);
};
#endif
