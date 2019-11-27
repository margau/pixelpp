#ifndef RGB_H
#define RGB_H

#include "common.h"

#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2
#define OFFSET(r, g, b) (((r) << 4) | ((g) << 2) | (b))

enum class LEDColor : uint8_t {
	RGB = OFFSET(COLOR_RED, COLOR_GREEN, COLOR_BLUE),
	GRB = OFFSET(COLOR_GREEN, COLOR_RED, COLOR_BLUE),
	RBG = OFFSET(COLOR_RED, COLOR_BLUE, COLOR_GREEN),
	BRG = OFFSET(COLOR_BLUE, COLOR_RED, COLOR_GREEN),
	BGR = OFFSET(COLOR_BLUE, COLOR_GREEN, COLOR_RED),
	GBR = OFFSET(COLOR_GREEN, COLOR_BLUE, COLOR_RED)
};

enum class LEDChannels : uint8_t {
	RGB = 3,
	RGBW = 4
};

typedef struct rgb {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} rgb;

typedef struct hsv {
	uint8_t hue;
	uint8_t sat;
	uint8_t val;
} hsv;

//#define ColorToRGB(color) {(((color) >> 16) & 0xFF, ((color) >> 8) & 0xFF, (color) & 0xFF)}

#endif
