#include "PixelPP.h"
#include "rgb.h"

PixelPP::PixelPP(uint16_t n, uint8_t * pix = NULL, LEDColor t = LEDColor::RGB, LEDChannels channels = LEDChannels::RGB) : _type(t), _num_leds(n), _channels(channels) {
	if(pix != NULL) {
		_leds = pix;
	} else {
		_leds = (uint8_t*)malloc(sizeof(struct rgb)*n);
	}
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

void PixelPP::setPixel(uint16_t n, rgb const & rgb)
{
	uint8_t rOffset = (_type >> 4) & 3;
	uint8_t gOffset = (_type >> 2) & 3;
	uint8_t bOffset = _type & 3;
	_leds[_channels * n + rOffset] = rgb.red;
	_leds[_channels * n + gOffset] = rgb.green;
	_leds[_channels * n + bOffset] = rgb.blue;
}
