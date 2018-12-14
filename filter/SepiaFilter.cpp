/*
	Weining Li
*/

#include "SepiaFilter.h"

/*
input:
output: SepiaFilter object initialized to default values.
Default constructor for SepiaFilter objects
*/
SepiaFilter::SepiaFilter() : PixelFilter("") {}

/*
input: name = name of the filter as a string
output: SepiaFilter object initialized to default values.
Parameter constructor for SepiaFilter objects
*/
SepiaFilter::SepiaFilter(string name) : PixelFilter(name) {}

/*
input:  s = const SepiaFilter object used to copy  from
output: SepiaFilter object initialized to values from s
Copy constructor for SepiaFilter objects
*/
SepiaFilter::SepiaFilter(const SepiaFilter& s) : PixelFilter(s.name) {}

// Destructor for header objects
SepiaFilter::~SepiaFilter() {}

/*
input: pix = pixel for using its RGB values.
output: pixel after applying sepia filter.
apply sepia filter to pixel with gamma_expansion and inverse_gamma functions.
*/
Pixel SepiaFilter::apply_transform(const Pixel& pix) const {
  double r, g, b;
  double outR, outG, outB;
  // pixel -> sRGB space -> linear space
  r = Pixel::gamma_expansion(pix.r() / 255.0);
  g = Pixel::gamma_expansion(pix.g() / 255.0);
  b = Pixel::gamma_expansion(pix.b() / 255.0);
  outR = (r * .393) + (g * .769) + (b * .189);
  outG = (r * .349) + (g * .686) + (b * .168);
  outB = (r * .272) + (g * .534) + (b * .131);
  // put values back in color space
  if (outR > 1.0) {
    outR = Pixel::inverse_gamma(1.0);
  } else if (outR < 1.0) {
    outR = Pixel::inverse_gamma(outR);
  }
  if (outG > 1.0) {
    outG = Pixel::inverse_gamma(1.0);
  } else if (outG < 1.0) {
    outG = Pixel::inverse_gamma(outG);
  }
  if (outB > 1.0) {
    outB = Pixel::inverse_gamma(1.0);
  } else if (outB < 1.0) {
    outB = Pixel::inverse_gamma(outB);
  }
  return Pixel(outR * 255, outG * 255, outB * 255);
}
