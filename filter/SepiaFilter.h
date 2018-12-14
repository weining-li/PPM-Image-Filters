/*
	Weining Li
*/

#ifndef SEPIA_H
#define SEPIA_H

#include "Filter.h"
#include "PixelFilter.h"

using namespace std;

class SepiaFilter : public PixelFilter {
  public:
    SepiaFilter();
    SepiaFilter(string);
    SepiaFilter(const SepiaFilter&);
    virtual ~SepiaFilter ();
    virtual Pixel apply_transform(const Pixel&) const;
  };

#endif
