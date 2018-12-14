/*
	Weining Li
*/

#include "KernelFilter.h"

/*
input:
output: KernelFilter object initialized to default values.
Default constructor for KernelFilter objects
*/
KernelFilter::KernelFilter() : Filter("") {}

/*
input: name = name of the filter as a string
output: Filter object initialized to default values.
Parameter constructor for filter objects
*/
KernelFilter::KernelFilter(string name) : Filter(name) {}

/*
input:  k = const header used to copy from
output: KernelFilter object initialized to values from k
Copy constructor for KernelFilter objects
*/
KernelFilter::KernelFilter(const KernelFilter& k) : Filter(k.name) {}

// Destructor for KernelFilter objects
KernelFilter::~KernelFilter() {}

/*
input:  img = image to apply kernel to
        kernel = kernel from SharpenFilter or BlurFilter
output: void
pass each pixel of img to apply_kernel.
*/
void KernelFilter::apply (Image& img, const Matrix& k) const {
  int k_center = k.size()/2;
  int img_rows = img.header().height();
  int img_cols = img.header().width();
  // creating temp image to use for reference
  Image copy(img);
  // apply kernel to pixel at [x][y]
  for (int y = k_center; y < img_rows-k_center; y++) {
    for (int x = k_center; x < img_cols-k_center; x++) {
      img(x,y) = this->apply_kernel(copy, x, y, k);
    }
  }
}

/*
input:  img - image to apply kernel to
        x - x coordinate of the pixel to apply kernel to
        y - y coordinate
        k - kernel used for filtering
output: filtered pixel
apply kernel to pixel at (x,y).
*/
Pixel KernelFilter::apply_kernel(Image& img, int x, int y, const Matrix& k)
  const {

  int k_center = k.size()/2;
  double r = 0.0, g = 0.0, b = 0.0;
    // apply kernel to center pixel by cycling through surrounding pixels
  for (int j = -k_center; j <= k_center; j++) {
    for (int i = -k_center; i <= k_center; i++) {
      Pixel& p = img(x+i,y+i);
      double modifier = k[k_center+i][k_center+j];
      r += p.r() * modifier;
      g += p.g() * modifier;
      b += p.b() * modifier;
    }
  }
  int out_r = static_cast<int>(r);
  int out_g = static_cast<int>(g);
  int out_b = static_cast<int>(b);
    // call clamp function to make sure the values are within 0-255
  out_r = clamp(0,255,out_r);
  out_g = clamp(0,255,out_g);
  out_b = clamp(0,255,out_b);
  return Pixel(out_r,out_g,out_b);
}
