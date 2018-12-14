/*
	Weining Li
*/

#include "HFlipFilter.h"

/*
input:
output: HFlipFilter object initialized to default values.
Default constructor for HFlipFilter objects
*/
HFlipFilter::HFlipFilter() : SimpleFilter("") {}

/*
input: name = name of the filter as a string
output: HFlipFilter object initialized to default values.
Parameter constructor for HFlipFilter objects
*/
HFlipFilter::HFlipFilter(string name) : SimpleFilter(name) {}

/*
input:  s = const header used to copy from
output: HFlipFilter object initialized to values from s
Copy constructor for HFlipFilter objects
*/
HFlipFilter::HFlipFilter(const HFlipFilter& s) : SimpleFilter(s.name) {}

// Destructor for header objects
HFlipFilter::~HFlipFilter() {}

/*
input:  img = img to apply HFlip filter
output: void
Apply HFlip to img by swapping pixels
*/
void HFlipFilter::apply(Image& img) const {
  for (int y = 0; y < img.header().height(); y++) {
    for (int x = 0; x < img.header().width() / 2; x++) {
      swap(img(x, y), img(img.header().width() - x, y));
    }
  }
}
