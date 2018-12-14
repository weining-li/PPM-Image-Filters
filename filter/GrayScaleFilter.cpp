/*
	Weining Li
*/

#include "GrayScaleFilter.h"

/*
input:
output: GrayScaleFilter object initialized to default values.
Default constructor for GrayScaleFilter objects
*/
GrayScaleFilter::GrayScaleFilter() : PixelFilter("") {}

/*
input: name = name of the filter as a string
output: GrayScaleFilter object initialized to default values.
Parameter constructor for GrayScaleFilter objects
*/
GrayScaleFilter::GrayScaleFilter(string name) : PixelFilter(name) {}

/*
input:  s = const GrayScaleFilter used to copy from
output: GrayScaleFilter object initialized to values from s
Copy constructor for GrayScaleFilter objects
*/
GrayScaleFilter::GrayScaleFilter(const GrayScaleFilter& s) :
  PixelFilter(s.name) {}

// Destructor for header objects
GrayScaleFilter::~GrayScaleFilter() {}

/*
input:  pix = pixel to apply grayscale to
output: grayscaled Pixel
apply grayscale to pixel using its luminance.
*/
Pixel GrayScaleFilter::apply_transform(const Pixel& pix) const {
  uint8_t grayValue = pix.luminance();
  return Pixel(grayValue, grayValue, grayValue);
}
