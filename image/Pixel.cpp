#include "Pixel.h"

/*
input:
output: image object initialized to default values.
Default constructor for image objects
*/
Pixel::Pixel () : R(0), G(0), B(0) {}

/*
input:  P = const pixel used to copy values from
output: pixel object initialized to values from P
Copy constructor for pixel objects
*/
Pixel::Pixel (const Pixel& P) : R(P.R), G(P.G), B(P.B) {}

/*
input:  P = pixel reference used to copy values from
output: pixel object initialized to values from P
Copy constructor for pixel objects
*/
Pixel::Pixel (Pixel&& P) : R(P.R), G(P.G), B(P.B) {}

/*
input:  r - red value of pixel
        g - green value of pixel
        b - blue value of pixel
output: pixel object initialized to specified parameters
Parameter constructor for pixel objects
*/
Pixel::Pixel (uint8_t R, uint8_t G, uint8_t B) : R(R), G(G), B(B) {}

// Destructor for pixel objects
Pixel::~Pixel() {}

/*
output: red value of pixel
        green value of pixel
        blue value of pixel
get red, green, and blue values of pixel
*/
uint8_t Pixel::r () const { return this->R; }
uint8_t Pixel::g () const { return this->G; }
uint8_t Pixel::b () const { return this->B; }

/*
output: red value of pixel as a refernce
        green value of pixel as a refernce
        blue value of pixel as a refernce
get red, green, and blue values of pixel as a refernce
*/
uint8_t& Pixel::r () { return this->R; }
uint8_t& Pixel::g () { return this->G; }
uint8_t& Pixel::b () { return this->B; }

/*
input:
output: "brightness" of a pixel as an uint8_t
calculate the luminance of a pixel using gamma_expansion and inverse_gamma.
*/
uint8_t Pixel::luminance () const {
  double lR, lG, lB;
  lR = Pixel::gamma_expansion((double)this->R/255.0);
  lG = Pixel::gamma_expansion((double)this->G/255.0);
  lB = Pixel::gamma_expansion((double)this->B/255.0);
  double lY = 0.2126*lR + 0.7152*lG + 0.0722*lB;
  double sY = lY > 1.0 ? inverse_gamma(1.0) : inverse_gamma(lY);
  return (uint8_t) (sY*255.0);
}

/*
input:  out - out file stream
        P - pixel
output: out file stream with values from P
Output operator overload
*/
ostream& operator<< (ostream& out, const Pixel& P) {
 return out  << "(" << (int)P.R << " "
                    << (int)P.G << " "
                    << (int)P.B << ")";
}

/*
input:  rhs - const pixel used to get values from
output: pixel object with values from rhs
Assignment operator overload
*/
Pixel& Pixel::operator= (const Pixel& rhs) {
  if (&rhs == this)
    return *this;
  this->R = rhs.R;
  this->G = rhs.G;
  this->B = rhs.B;
  return *this;
}

/*
input:  rhs - pixel reference used to get values from
output: pixel object with values from rhs
Assignment operator overload
*/
Pixel& Pixel::operator= (Pixel&& rhs) {
  this->R = rhs.R;
  this->G = rhs.G;
  this->B = rhs.B;
  return *this;
}
