#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "common.h"
#include "PixelPP.h"

class Effect
{
protected:
    PixelPP* _parent;
public:
    Effect(PixelPP* parent);
    virtual void render();
};
#endif