#include "StrobeEffect.hpp"

StrobeEffect::StrobeEffect(PixelPP* parent, uint16_t on, uint16_t off) : _on(on), _off(off), Effect(parent)
{
	_period = on + off;
}

StrobeEffect::~StrobeEffect()
{
}

void StrobeEffect::render(unsigned long t)
{
	uint16_t now = t % _period;
	uint16_t numPixels = _parent->getNumLeds();
	if(now < _on) {
		// Do Nothing with pix
	} else {
		// Set Pix off
		for (uint16_t i = 0; i < numPixels; i++)
                {
                        rgb& pix = _parent->_leds_rgb[i];
                        pix.red = 0;
                        pix.green = 0;
                        pix.blue = 0;
                }

	}
}
