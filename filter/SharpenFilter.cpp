/*
	Weining Li
*/

#include "SharpenFilter.h"

const Matrix SharpenFilter::K3 =
{{ 0 ,-1 , 0 },
 {-1 , 5 ,-1 },
 { 0 ,-1 , 0 }};

 /*
 input:
 output: KernelFilter object initialized to default values.
 Default constructor for KernelFilter objects
 */
SharpenFilter::SharpenFilter() : KernelFilter("") {}

/*
input: name = name of the filter as a string
output: KernelFilter object initialized to default values.
Parameter constructor for KernelFilter objects
*/
SharpenFilter::SharpenFilter(string name) : KernelFilter(name) {}

/*
input:  s = const SharpenFilter used to copy from
output: SharpenFilter object initialized to values from s
Copy constructor for SharpenFilter objects
*/
SharpenFilter::SharpenFilter(const SharpenFilter& s) : KernelFilter(s.name) {}

// Destructor for header objects
SharpenFilter::~SharpenFilter() {}

/*
input:  img to apply the SharpenFilter
output: void
pass image and SharpenFilter's kernel to KernelFilter's apply function.
*/
void SharpenFilter::apply(Image& img) const {
  KernelFilter::apply(img, SharpenFilter::K3);
}
