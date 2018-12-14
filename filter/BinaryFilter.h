/*
	Weining Li
*/


#ifndef BINARY_H
#define BINARY_H

#include "Filter.h"
#include "PixelFilter.h"

using namespace std;

class BinaryFilter : public PixelFilter {
  private:
    Pixel pixel1, pixel2;
  public:
    BinaryFilter();
    BinaryFilter(string, int, int, int, int, int, int);
    BinaryFilter(const BinaryFilter&);
    virtual ~BinaryFilter ();
    virtual Pixel apply_transform(const Pixel&) const;
  };

#endif
