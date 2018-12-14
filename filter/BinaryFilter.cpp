/*
	Weining Li
 */

#include "BinaryFilter.h"

/*
input:
output: BinaryFilter object initialized to default values.
Default constructor for BinaryFilter objects
*/
BinaryFilter::BinaryFilter() :
  PixelFilter(""), pixel1(0, 0, 0), pixel2(255, 255, 255) {}

/*
input: name = name of the filter as a string
       r1, g1, b1 = RGB values for pixel1
       r2, g2, b2 = RGB values for pixel2
output: BinaryFilter object initialized to default values.
Parameter constructor for BinaryFilter objects
*/
BinaryFilter::BinaryFilter(string name,
  int r1, int g1, int b1, int r2, int g2, int b2) :
  PixelFilter(name), pixel1(r1, g1, b1) , pixel2(r2, g2, b2) {}

/*
input:  s = const BinaryFilter object used to copy from
output: BinaryFilter object initialized to values from s
Copy constructor for BinaryFilter objects
*/
BinaryFilter::BinaryFilter(const BinaryFilter& s) :
  PixelFilter(s.name), pixel1(s.pixel1), pixel2(s.pixel2) {}

// Destructor for BinaryFilter objects
BinaryFilter::~BinaryFilter() {}

/*
input:  pix = pixel to apply transformation.
output: pixel1 or pixel2 depending on luminance.
Determine what color the pixel should be based on its luminance.
*/
Pixel BinaryFilter::apply_transform(const Pixel& pix) const {
  if (pix.luminance() <= (255 / 2)) {
    return pixel1;
  } else {
    return pixel2;
  }
}
