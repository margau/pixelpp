#ifndef SAWTOOTHEFFECT_HPP
#define SAWTOOTHEFFECT_HPP
#include "common.h"
#include "rgb.h"
#include "PixelPP.hpp"
#include "Effect.hpp"

#define INT16_BITS  (8 * sizeof(int16_t))
#ifndef INT16_MAX
#define INT16_MAX   ((1<<(INT16_BITS-1))-1)
#endif

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
