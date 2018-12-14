/*
	Weining Li
*/

#include "SimpleFilter.h"

/*
input:
output: SimpleFilter object initialized to default values.
Default constructor for SimpleFilter objects
*/
SimpleFilter::SimpleFilter() : Filter("") {}

/*
input: name = name of the filter as a string
output: SimpleFilter object initialized to default values.
Parameter constructor for SimpleFilter objects
*/
SimpleFilter::SimpleFilter(string name) : Filter(name) {}

/*
input:  s = const SimpleFilter used to copy from
output: SimpleFilter object initialized to values from s
Copy constructor for SimpleFilter objects
*/
SimpleFilter::SimpleFilter(const SimpleFilter& s) : Filter(s.name) {}

// Destructor for header objects
SimpleFilter::~SimpleFilter() {}
