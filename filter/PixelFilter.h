/*
	Weining Li
*/

#ifndef PIXELFILT_H
#define PIXELFILT_H

#include "Filter.h"

using namespace std;

class PixelFilter : public Filter {
  protected:
    PixelFilter();
    PixelFilter(string);
    PixelFilter(const PixelFilter&);

  public:
    virtual ~PixelFilter () = 0;
    virtual void apply (Image&) const;
    virtual Pixel apply_transform(const Pixel&) const = 0;
  };

#endif
