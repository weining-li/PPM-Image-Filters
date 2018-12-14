/*
	Weining Li
*/

#include "VFlipFilter.h"

/*
input:
output: VFlipFilter object initialized to default values.
Default constructor for VFlipFilter objects
*/
VFlipFilter::VFlipFilter() : SimpleFilter("") {}

/*
input: name = name of the filter as a string
output: VFlipFilter object initialized to default values.
Parameter constructor for VFlipFilter objects
*/
VFlipFilter::VFlipFilter(string name) : SimpleFilter(name) {}

/*
input:  s = const VFlipFilter object used to copy from
output: VFlipFilter object initialized to values from s
Copy constructor for VFlipFilter objects
*/
VFlipFilter::VFlipFilter(const VFlipFilter& s) : SimpleFilter(s.name) {}

// Destructor for VFlipFilter objects
VFlipFilter::~VFlipFilter() {}


/*
input:  img = img to apply VFlip filter
output: void
Apply VFlip to img by swapping pixels
*/
void VFlipFilter::apply(Image& img) const {
  for (int y = 0; y < img.header().height() / 2; y++) {
    for (int x = 0; x < img.header().width(); x++) {
      swap(img(x, y), img(x, img.header().height() - y));
    }
  }
}
