#include "Image.h"

/*
input:  in - input file with parameters
output: image object initialized to specified parameters
Parameter constructor for image objects
*/
Image::Image (ifstream& in) :
  HDR (Image::read_header(in)), PIX (Image::read_pixels(HDR, in)) {}

/*
input:  image = const image used to copy values from
output: image object initialized to values from img
Copy constructor for image objects
*/
Image::Image (const Image& img) :
  HDR(img.header()), PIX(img.pixels()) {}

// Destructor for Image objects
Image::~Image () {}

// get header
const Header& Image::header () const { return this->HDR; }

// get vector of pixels
const vector<Pixel>& Image::pixels () const { return this->PIX; }

/*
input:  x - x coordinate of the pixel
        y - y coordinate
output: pixel at (x,y)
operator overloading used to get one pixel directly from image
*/
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->PIX[ndx];
}

/*
input:  in - input file to get values from
output: header with values from input file
read values from input file to a header object while skipping comments
*/
Header Image::read_header (ifstream& in) {
  string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}

/*
input:  in - input file with possible comments in header
ignore comments in the header
*/
void Image::ignore_comments (ifstream& in) {
  char c;
  in.get(c);

  while (isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}

/*
input:  hdr - header with information needed for reading pixels
        in - input file from where to read pixels
output: vector of pixels with values from input file
read pixels from input file to a vector
*/
vector<Pixel> Image::read_pixels (const Header& hdr, ifstream& in) {
  int num_pixels = hdr.width() * hdr.height();
  vector<Pixel> pixels(num_pixels);

  if (hdr.magic() == "P3") {
    uint r,g,b;
    for (Pixel& p : pixels) {
      in >> r >> g >> b;
      p = Pixel(r, g, b);
    }
  } else {
    uint8_t r,g,b;
    for (Pixel& p : pixels) {
      r = in.get();
      g = in.get();
      b = in.get();
      p = Pixel(r, g, b);
    }
  }

  return pixels;
}

// changes header to P3
void Image::make_p3 () { this->HDR.magic() = "P3"; }

// changes header to P6
void Image::make_p6 () { this->HDR.magic() = "P6"; }

/*
input:  out - output file
writes header to output file
*/
void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

/*
input:  out - output file
writes header and pixels to output file
*/
void Image::write_to (ofstream& out) const {
  write_header(out);

  if (this->HDR.magic() == "P3") {
    for (const Pixel& p : this->PIX) {
      out << (int) p.r() << ' '
          << (int) p.g() << ' '
          << (int) p.b() << ' ';
    }
  } else {
    for (const Pixel& p : this->PIX) {
      out << p.r() << p.g() << p.b();
    }
  }
}
