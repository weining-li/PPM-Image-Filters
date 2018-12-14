/*
	Weining Li
*/

#ifndef SIMPLE_H
#define SIMPLE_H

#include "Filter.h"

using namespace std;

class SimpleFilter : public Filter {
  protected:
    SimpleFilter();
    SimpleFilter(string);
    SimpleFilter(const SimpleFilter&);

  public:
    virtual ~SimpleFilter () = 0;
    virtual void apply (Image&) const = 0;
  };

  #endif
