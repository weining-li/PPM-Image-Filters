/*
   Weining Li
*/

#include "filter/SharpenFilter.h"
#include "filter/BlurFilter.h"
#include "filter/HFlipFilter.h"
#include "filter/VFlipFilter.h"
#include "filter/BinaryFilter.h"
#include "filter/SepiaFilter.h"
#include "filter/GrayScaleFilter.h"
#include "image/Image.h"

using namespace std;

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		std::cerr << "USAGE: ./out <in.ppm>";
		return 1;
	}

	// put together output files' names
	string sharpenF = "output/sharpen_100.ppm";
  string binaryF = "output/binary_100.ppm";
  string grayscaleF = "output/grayscale_100.ppm";
  string sepiaF = "output/sepia_100_ec.ppm";
  string blurF = "output/blur_100.ppm";
  string horizontalF = "output/horizontal_100.ppm";
  string verticalF = "output/vertical_100.ppm";
  string sbhF = "output/shar_bin_hf_100.ppm";
  string ssvF = "output/shar_sep_vf_100.ppm";
  string sghF = "output/shar_gs_hf_100.ppm";
  string bgvF = "output/blur_gs_vf_100.ppm";
  string bbhF = "output/blur_bin_hf_100.ppm";
  string bsvF = "output/blur_sep_vf_100.ppm";
  string scF = "output/stud_creation_100.ppm";

	// input stream to files
  ifstream in_sharpenF(argv[1]);
  ifstream in_binaryF(argv[1]);
  ifstream in_grayscaleF(argv[1]);
  ifstream in_sepiaF(argv[1]);
  ifstream in_blurF(argv[1]);
  ifstream in_horizontalF(argv[1]);
  ifstream in_verticalF(argv[1]);
  ifstream in_sbhF(argv[1]);
  ifstream in_ssvF(argv[1]);
  ifstream in_sghF(argv[1]);
  ifstream in_bgvF(argv[1]);
  ifstream in_bbhF(argv[1]);
  ifstream in_bsvF(argv[1]);
  ifstream in_scF(argv[1]);
	ofstream out_sharpenF(sharpenF);
  ofstream out_binaryF(binaryF);
  ofstream out_grayscaleF(grayscaleF);
  ofstream out_sepiaF(sepiaF);
  ofstream out_blurF(blurF);
  ofstream out_horizontalF(horizontalF);
  ofstream out_verticalF(verticalF);
  ofstream out_sbhF(sbhF);
  ofstream out_ssvF(ssvF);
  ofstream out_sghF(sghF);
  ofstream out_bgvF(bgvF);
  ofstream out_bbhF(bbhF);
  ofstream out_bsvF(bsvF);
  ofstream out_scF(scF);

	if (!(in_sharpenF && in_binaryF && in_grayscaleF && in_sepiaF && in_blurF &&
				in_horizontalF && in_verticalF && in_sbhF && in_ssvF && in_sghF &&
				in_bgvF && in_bbhF && in_bsvF && in_scF && out_sharpenF &&
				out_binaryF && out_grayscaleF && out_sepiaF && out_blurF &&
				out_horizontalF && out_verticalF && out_sbhF && out_ssvF && out_sghF &&
				out_bgvF && out_bbhF && out_bsvF && out_scF)) {
		std::cerr << "Could not open input/output\n";
		return 1;
	}

	// initialize image from files
  Image sharpen_img(in_sharpenF);
  Image binary_img(in_binaryF);
  Image grayscale_img(in_grayscaleF);
  Image sepia_img(in_sepiaF);
  Image blur_img(in_blurF);
  Image horizontal_img(in_horizontalF);
  Image vertical_img(in_verticalF);
  Image sbh_img(in_sbhF);
  Image ssv_img(in_ssvF);
  Image sgh_img(in_sghF);
  Image bgv_img(in_bgvF);
  Image bbh_img(in_bbhF);
  Image bsv_img(in_bsvF);
  Image sc_img(in_scF);


	// getting RGB values for binary filter
	int r1, g1, b1, r2, g2, b2;
	cout << "Enter the 3 RGB values for color 1 of the binary filter. (0-255)\n";
	cin >> r1 >> g1 >> b1;
	cout << "Enter the 3 RGB values for color 2 of the binary filter. (0-255)\n";
	cin >> r2 >> g2 >> b2;

	// instantiate filter classes
  SharpenFilter shar;
  BinaryFilter bin("", r1, g1, b1, r2, g2, b2);
  GrayScaleFilter gs;
  SepiaFilter sep;
  BlurFilter blur;
  HFlipFilter hf;
	VFlipFilter vf;

	// applying filters
	shar.apply(sharpen_img);
  bin.apply(binary_img);
  gs.apply(grayscale_img);
  sep.apply(sepia_img);
  blur.apply(blur_img);
  hf.apply(horizontal_img);
	vf.apply(vertical_img);

  shar.apply(sbh_img);
  bin.apply(sbh_img);
  hf.apply(sbh_img);

  shar.apply(ssv_img);
  sep.apply(ssv_img);
  vf.apply(ssv_img);

  shar.apply(sgh_img);
  gs.apply(sgh_img);
  hf.apply(sgh_img);

  blur.apply(bgv_img);
  gs.apply(bgv_img);
  vf.apply(bgv_img);

  blur.apply(bbh_img);
  bin.apply(bbh_img);
  hf.apply(bbh_img);

  blur.apply(bsv_img);
  sep.apply(bsv_img);
	vf.apply(bsv_img);

	shar.apply(sc_img);
  bin.apply(sc_img);
  sep.apply(sc_img);
  blur.apply(sc_img);
  hf.apply(sc_img);

	// write to output files
	sharpen_img.write_to(out_sharpenF);
  binary_img.write_to(out_binaryF);
  grayscale_img.write_to(out_grayscaleF);
  sepia_img.write_to(out_sepiaF);
  blur_img.write_to(out_blurF);
  horizontal_img.write_to(out_horizontalF);
  vertical_img.write_to(out_verticalF);
  sbh_img.write_to(out_sbhF);
  ssv_img.write_to(out_ssvF);
  sgh_img.write_to(out_sghF);
  bgv_img.write_to(out_bgvF);
  bbh_img.write_to(out_bbhF);
  bsv_img.write_to(out_bsvF);
  sc_img.write_to(out_scF);

	// close file streams
  in_sharpenF.close();
  in_binaryF.close();
  in_grayscaleF.close();
  in_sepiaF.close();
  in_horizontalF.close();
  in_verticalF.close();
  in_sbhF.close();
  in_ssvF.close();
  in_sghF.close();
  in_bgvF.close();
  in_bbhF.close();
  in_bsvF.close();
  in_scF.close();
	out_sharpenF.close();
  out_binaryF.close();
  out_grayscaleF.close();
  out_sepiaF.close();
  out_blurF.close();
  out_horizontalF.close();
  out_verticalF.close();
  out_sbhF.close();
  out_ssvF.close();
  out_sghF.close();
  out_bgvF.close();
  out_bbhF.close();
  out_bsvF.close();
  out_scF.close();

	return 0;
}
