/*
	Weining Li
*/

#ifndef HFLIP_H
#define HFLIP_H

#include "Filter.h"
#include "SimpleFilter.h"

using namespace std;

class HFlipFilter : public SimpleFilter {
  public:
    HFlipFilter();
    HFlipFilter(string);
    HFlipFilter(const HFlipFilter&);
    virtual ~HFlipFilter ();
    virtual void apply (Image&) const;
};

#endif
