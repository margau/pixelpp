#include "common.h"
#include "rgb.h"
#include "PixelPP.h"

class FillEffect
{
private:
    rgb _color;
    PixelPP* _parent;
public:
    FillEffect(PixelPP* parent, rgb color);
    ~FillEffect();
    void render();
};