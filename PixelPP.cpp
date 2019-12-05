#include "PixelPP.hpp"
#include "rgb.h"

PixelPP::PixelPP(uint16_t n, uint8_t * pix, LEDColor t, LEDChannels channels) : _type(t), _num_leds(n), _channels(channels) {
	if(pix != NULL) {
		_leds = pix;
	} else {
		_leds = (uint8_t*)malloc(sizeof(rgb)*n);
	}
	_leds_rgb = (rgb*)malloc(sizeof(rgb)*n);
}

PixelPP::~PixelPP() {

}

void PixelPP::render(void) {
	uint32_t time = millis();
	 for (uint16_t i = 0; i < _num_leds; i++)
        {
		_leds_rgb[i] = {0,0,0};
        }
	for (Effect* effect: _effects)
	{
		effect->render(time);
	}
	for (uint16_t i = 0; i < _num_leds; i++)
	{
		this->setPixel(i, _leds_rgb[i]);
	}
}

PixelPP* PixelPP::addEffect(Effect* effect)
{
	_effects.push_back(effect);
	Serial.println("Effect added, now " + String((uint8_t)_effects.size()) + " effects.");
	return this;
}

void PixelPP::clearEffects()
{
	for (Effect* e: _effects)
	{
		delete e;
	}
	_effects.clear();
}

uint16_t PixelPP::getNumLeds()
{
	return _num_leds;
}

void PixelPP::setPixel(uint16_t n, rgb const & rgb)
{
	uint8_t rOffset = ((uint8_t)_type >> 4) & 3;
	uint8_t gOffset = ((uint8_t)_type >> 2) & 3;
	uint8_t bOffset = (uint8_t)_type & 3;
	_leds[((uint8_t)_channels * n) + rOffset] = rgb.red;
	_leds[((uint8_t)_channels * n) + gOffset] = rgb.green;
	_leds[((uint8_t)_channels * n) + bOffset] = rgb.blue;
}
