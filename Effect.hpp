#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "common.h"

class PixelPP;
class Effect
{
protected:
    PixelPP *_parent;
public:
    Effect(PixelPP* parent);
    ~Effect();
    virtual void render() = 0;
};
#endif
