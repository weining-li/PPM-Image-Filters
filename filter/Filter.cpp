/*
	Weining Li
*/

#include "Filter.h"

/*
input:
output: Filter object initialized to default values.
Default constructor for filter objects
*/
Filter::Filter() :
  name("") {}

/*
input: name = name of the filter as a string
output: Filter object initialized to default values.
Parameter constructor for filter objects
*/
Filter::Filter(string name) :
  name(name) {}

  /*
  input:  f = const Filter used to copy from
  output: Filter object initialized to values from f
  Copy constructor for Filter objects
  */
Filter::Filter(const Filter& f) :
  name(f.name)  {}

// Destructor for Filter objects
Filter::~Filter() {}

/*
input:  lo - the lower limit of the value of a pixel as an int
        hi - the higher limit of the value of a pixel as an int
        x - the filtered value as an int
output: an int that is within the limits of the value of the pixel
make sure the value of a pixel is within limits
*/
int Filter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

/*
input:  lo - the lower limit of the value of a pixel as a double
        hi - the higher limit of the value of a pixel as a double
        x - the filtered value as a double
output: a double that is within the limits of the value of the pixel
make sure the value of a pixel is within limits
*/
double Filter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
