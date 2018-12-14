/*
	Weining Li
*/

#include "PixelFilter.h"

/*
input:
output: PixelFilter object initialized to default values.
Default constructor for PixelFilter objects
*/
PixelFilter::PixelFilter() : Filter("") {}

/*
input: name = name of the filter as a string
output: PixelFilter object initialized to default values.
Parameter constructor for PixelFilter objects
*/
PixelFilter::PixelFilter(string name) : Filter(name) {}

/*
input:  k = const PixelFilter used to copy from
output: PixelFilter object initialized to values from k
Copy constructor for PixelFilter objects
*/
PixelFilter::PixelFilter(const PixelFilter& k) : Filter(k.name) {}

// Destructor for PixelFilter objects
PixelFilter::~PixelFilter() {}

/*
input:  img = img to use apply transform on.
output: void
Use apply_transform function on each pixel of img.
*/
void PixelFilter::apply (Image& img) const{
  int rows = img.header().height();
  int cols = img.header().width();
  Image copy(img);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      img(x,y) = this->apply_transform(copy(x,y));
    }
  }
}
