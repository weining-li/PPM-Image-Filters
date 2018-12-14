/*
	Weining Li
*/

#ifndef VFLIP_H
#define VFLIP_H

#include "Filter.h"
#include "SimpleFilter.h"

using namespace std;

class VFlipFilter : public SimpleFilter {
  public:
    VFlipFilter();
    VFlipFilter(string);
    VFlipFilter(const VFlipFilter&);
    virtual ~VFlipFilter ();
    virtual void apply (Image&) const;
};

#endif
