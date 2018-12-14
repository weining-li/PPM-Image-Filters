/*
	Weining Li
*/

#ifndef BLUR_H
#define BLUR_H

#include "KernelFilter.h"

using namespace std;

class BlurFilter : public KernelFilter {
  protected:
    static const Matrix K3;

  public:
    BlurFilter();
    BlurFilter(string);
    BlurFilter(const BlurFilter&);
    virtual ~BlurFilter ();
    virtual void apply(Image&) const;
};

#endif
