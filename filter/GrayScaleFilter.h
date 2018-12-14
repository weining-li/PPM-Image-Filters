/*
	Weining Li
*/

#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "Filter.h"
#include "PixelFilter.h"

using namespace std;

class GrayScaleFilter : public PixelFilter {
  public:
    GrayScaleFilter();
    GrayScaleFilter(string);
    GrayScaleFilter(const GrayScaleFilter&);
    virtual ~GrayScaleFilter ();
    virtual Pixel apply_transform(const Pixel&) const;
  };

#endif
