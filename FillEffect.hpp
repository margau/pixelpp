#include "common.h"
#include "rgb.h"
#include "PixelPP.h"
#include "Effect.hpp"

class FillEffect : Effect
{
private:
    rgb _color;
public:
    FillEffect(PixelPP* parent, rgb color);
    ~FillEffect();
    void render();
};