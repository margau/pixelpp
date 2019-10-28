#include "PixelPP.h"
#include "rgb.h"

PixelPP::PixelPP(uint16_t n, colorType t, uint8_t * pix) {
	if(pix != NULL) {
		_leds = (struct rgb*) pix;
	} else {
		_leds = (struct rgb*)malloc(sizeof(struct rgb)*n);
	}
	_num_leds = n;
}

PixelPP::~PixelPP() {

}

void PixelPP::render(void) {
	for (Effect* effect: _effects)
	{
		effect->render();
	}
}

PixelPP* PixelPP::addEffect(Effect* effect)
{
	_effects.push_back(effect);
	return this;
}

uint16_t PixelPP::getNumLeds()
{
	return _num_leds;
}

rgb* PixelPP::getLeds()
{
	return _leds;
}
