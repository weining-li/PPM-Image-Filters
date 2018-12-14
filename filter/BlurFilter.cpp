/*
	Weining Li
*/

#include "BlurFilter.h"

const Matrix BlurFilter::K3 =
{{ 0.0625 , 0.125 , 0.0625 },
 { 0.125  , 0.25  , 0.125  },
 { 0.0625 , 0.125 , 0.0625 }};

 /*
 input:
 output: BlurFilter object initialized to default values.
 Default constructor for BlurFilter objects
 */
BlurFilter::BlurFilter() : KernelFilter("") {}

/*
input: name = name of the filter as a string
output: BlurFilter object initialized to default values.
Parameter constructor for BlurFilter objects
*/
BlurFilter::BlurFilter(string name) : KernelFilter(name) {}

/*
input:  s = const header used to copy from
output: BlurFilter object initialized to values from s
Copy constructor for BlurFilter objects
*/
BlurFilter::BlurFilter(const BlurFilter& s) : KernelFilter(s.name) {}

// Destructor for header objects
BlurFilter::~BlurFilter() {}

/*
input:  img = image to apply blur
output: void
pass img and blur kernel to KernelFilter's apply function.
*/
void BlurFilter::apply(Image& img) const {
  KernelFilter::apply(img, BlurFilter::K3);
}
