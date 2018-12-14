/*
	Weining Li
*/

#ifndef KERNEL_H
#define KERNEL_H

#include "Filter.h"

using namespace std;
using Matrix = vector<vector<double>>;

class KernelFilter : public Filter {
  protected:
    KernelFilter();
    KernelFilter(string);
    KernelFilter(const KernelFilter&);

  public:
    virtual ~KernelFilter () = 0;
    virtual void apply (Image&) const = 0;
    virtual void apply (Image& img, const Matrix& k) const;
    virtual Pixel apply_kernel(Image&, int, int, const Matrix&) const;
};

#endif
