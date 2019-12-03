#ifndef SAWTOOTHEFFECT_HPP
#define SAWTOOTHEFFECT_HPP
#include "common.h"
#include "rgb.h"
#include "PixelPP.hpp"
#include "Effect.hpp"

class SawtoothEffect : public Effect
{
private:
	uint8_t _width;
	uint16_t _peri;
public:
	SawtoothEffect(PixelPP* parent, uint8_t width, uint16_t period);
	~SawtoothEffect();
	void render(unsigned long t);
	void reset();
};
#endif
