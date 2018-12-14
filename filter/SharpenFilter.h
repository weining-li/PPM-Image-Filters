/*
	Weining Li
*/

#ifndef SHARPEN_H
#define SHARPEN_H

#include "KernelFilter.h"

using namespace std;

class SharpenFilter : public KernelFilter {
  protected:
    static const Matrix K3;

  public:
    SharpenFilter();
    SharpenFilter(string);
    SharpenFilter(const SharpenFilter&);
    virtual ~SharpenFilter ();
    virtual void apply(Image&) const;
};

#endif
