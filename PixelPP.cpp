#include "PixelPP.h"
#include "rgb.h"

PixelPP::PixelPP(uint16_t n, colorType t, uint8_t * pix) {
        if(pix != NULL) {
                _leds = (struct rgb*) pix;
        } else {
                _leds = (struct rgb*)malloc(sizeof(struct rgb)*n);
        }
}

PixelPP::~PixelPP() {

}

void PixelPP::render(void) {
    for (Effect effect: _effects)
    {
        effect.render();
    }
}

void PixelPP::addEffect(Effect & effect)
{
    _effects.push_back(effect);
}