#include "Header.h"

/*
input:
output: Header object initialized to default values.
Default constructor for header objects
*/
Header::Header () :
  MAGIC(""), W(0), H(0), MC(0) {}

/*
input:  HDR = const header used to copy values from
output: Header object initialized to values from HDR
Copy constructor for header objects
*/
Header::Header (const Header& HDR) :
  MAGIC(HDR.MAGIC), W(HDR.W), H(HDR.H), MC(HDR.MC) {}

/*
input:  m - magic number of ppm image
        w - width of ppm image
        h - height of ppm image
        mc - max color of ppm image
output: header object initialized to specified parameters
Parameter constructor for header objects
*/
Header::Header (string m, int w, int h, int mc) :
  MAGIC(m), W(w), H(h), MC(mc) {}

// Destructor for header objects
Header::~Header () {}

/*
output: magic number of the ppm
get magic number from the header
*/
string Header::magic () const { return this->MAGIC; }

/*
output: width of the ppm
get width from the header
*/
int Header::width () const { return this->W; }

/*
output: height of the ppm
get height from the header
*/
int Header::height () const { return this->H; }

/*
output: max color of the ppm
get max color from the header
*/
int Header::max_color () const { return this->MC; }

/*
output: reference of magic number of the ppm
get reference of magic number from the header
*/
string& Header::magic () { return this->MAGIC; }

/*
output: eference of width of the ppm
get eference of width from the header
*/
int& Header::width () { return this->W; }

/*
output: eference of height of the ppm
get eference of height from the header
*/
int& Header::height () { return this->H; }

/*
output: eference of max color of the ppm
get eference of max color from the header
*/
int& Header::max_color () { return this->MC; }

/*
input:  hdr - header used to get values from
output: header object with values from hdr
Assignment operator overload
*/
Header& Header::operator= (const Header& hdr) {
  this->MAGIC = hdr.MAGIC;
  this->W     = hdr.W;
  this->H     = hdr.H;
  this->MC    = hdr.MC;
  return *this;
}

/*
input:  out - out file stream
        hdr - header
output: out file stream with values from header
Output operator overload
*/
ostream& operator<< (ostream& out, const Header& hdr) {
  return out << hdr.magic() <<  endl
      << hdr.width() <<  endl
      << hdr.height() <<  endl
      << hdr.max_color() <<  endl;
}
