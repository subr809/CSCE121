#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
	int* seam = new int[length];
	for (int i = 0; i < length; ++i) {
		seam[i] = 0;
	}
  return seam;
}

void deleteSeam(int* seam) {
	delete seam;
}



bool loadImage(string filename, Pixel** image, int width, int height) {
	cout << "Loading image..." << endl;
	// declare/define and open input file stream
	ifstream ifs;
	ifs.open(filename);
	// check if input stream opened successfully
	if (!ifs.is_open()) {
		cout << "Error: failed to open input file - " << filename << endl;
		return false;
	}
	// get type from preamble
	char type[3];
	ifs >> type; // should be P3
	if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
		cout << "Error: type is " << type << " instead of P3" << endl;
		return false;
	}
	  
	  // get width (w) and height (h) from preamble
	int w = 0, h = 0;
	ifs >> w;
	if (ifs.fail()) {
		cout << "Error: read non-integer value" << endl;
		return false;
	}
	ifs >> h;
	if (ifs.fail()) {
		cout << "Error: read non-integer value" << endl;
		return false;
	}
	if (w != width) { // check that width matches what was passed into the function
		cout << "Error: input width (" << width << ") does not match value in file (" << w << ")" << endl;
		return false;
	}
	if (h != height) { // check that height matches what was passed into the function
		cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
		return false;
	}
	  
	  // get maximum value from preamble
	int colorMax = 0;
	ifs >> colorMax;
	if (ifs.fail()) {
		cout << "Error: read non-integer value" << endl; 
		return false;
	}
	if (colorMax != 255) {
		cout << "Error: file is not using RGB color values." << endl;
		return false;
	}
	  // get RGB pixel values
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			ifs >> image[i][j].r;
			if (ifs.fail()) {
				if (ifs.eof()) {
					cout << "Error: not enough color values"  << endl;
					return false;
				}
				else {
					cout << "Error: read non-integer value" << endl;
					return false;
				}
			}
			if (image[i][j].r > 255) {
				cout << "Error: invalid color value " << image[i][j].r << endl;
				return false;
			}
			if (image[i][j].r < 0) {
				cout << "Error: invalid color value " << image[i][j].r << endl;
				return false;
			}
			ifs >> image[i][j].g;
			if (ifs.fail()) {
				if (ifs.eof()) {
					cout << "Error: not enough color values"  << endl;
					return false;
				}
				else {
					cout << "Error: read non-integer value" << endl;
					return false;
				}
			}
			if (image[i][j].g > 255) {
				cout << "Error: invalid color value " << image[i][j].g << endl;
				return false;
			}
			if (image[i][j].g < 0) {
				cout << "Error: invalid color value " << image[i][j].g << endl;
				return false;
			}
			ifs >> image[i][j].b;
			if (ifs.fail()) {
				if (ifs.eof()) {
					cout << "Error: not enough color values"  << endl;
					return false;
				}
				else {
					cout << "Error: read non-integer value" << endl;
					return false;
				}
			}
			if (image[i][j].b > 255) {
				cout << "Error: invalid color value " << image[i][j].b << endl;
				return false;
			}
			if (image[i][j].b < 0) {
				cout << "Error: invalid color value " << image[i][j].b << endl;
				return false;
			}
		}
	}
	int r;
	ifs >> r;
	if (r >= 0) {
			cout << "Error: too many color values" << endl;
		}
	ifs.close();
	// complete this part
	return true;
}




bool outputImage(string filename, Pixel** image, int width, int height) {
	cout << "Outputting image..." << endl;
	// declare/define and open output file stream
	ofstream ofs;
	ofs.open(filename);
	// check if output stream opened successfully
	if (!ofs.is_open()) {
		cout << "Error: failed to open output file " << filename << endl;
	}
	// output preamble
	ofs << "P3" << endl;
	ofs << width << ' ' << height << endl;
	ofs << "255" << endl; 
	// output pixels
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			ofs << image[i][j].r << ' ';
			ofs << image[i][j].g << ' ';
			ofs << image[i][j].b << ' ';
		}
	}
	ofs.close();
	return true;
}

int energy(Pixel** image, int x, int y, int width, int height) { 
  int xdiff, ydiff, totalenergy;
  if (x == 0) {
	  xdiff = pow((image[x+1][y].r - image[width-1][y].r), 2) + pow((image[x+1][y].g - image[width-1][y].g), 2) + pow((image[x+1][y].b - image[width-1][y].b), 2);
  }
  else if (x == width-1) {
	  xdiff = pow((image[x-1][y].r - image[0][y].r), 2) + pow((image[x-1][y].g - image[0][y].g), 2) + pow((image[x-1][y].b - image[0][y].b), 2);
  }
  else {
	  xdiff = pow((image[x+1][y].r - image[x-1][y].r), 2) + pow((image[x+1][y].g - image[x-1][y].g), 2) + pow((image[x+1][y].b - image[x-1][y].b), 2);
  }
  if (y == 0) {
	  ydiff = pow((image[x][y+1].r - image[x][height-1].r), 2) + pow((image[x][y+1].g - image[x][height-1].g), 2) + pow((image[x][y+1].b - image[x][height-1].b), 2);
  }
  else if (y == height -1) {
	  ydiff = pow((image[x][y-1].r - image[x][0].r), 2) + pow((image[x][y-1].g - image[x][0].g), 2) + pow((image[x][y-1].b - image[x][0].b), 2);
  }
  else {
	  ydiff = pow((image[x][y-1].r - image[x][y+1].r), 2) + pow((image[x][y-1].g - image[x][y+1].g), 2) + pow((image[x][y-1].b - image[x][y+1].b), 2);
  }
  totalenergy = xdiff + ydiff;
  return totalenergy;
}
  

// implement for part 2

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
	int seamenergy = 0;
	int minenergy = 0;
	int minenergyleft = 0;
	int minenergyright = 0;
	int minenergyindex = start_col;
	for (int j = 0; j < height; ++j) {
		if (j > 0) {
			if (minenergyindex > 0 && minenergyindex < width - 1) {
				minenergy = energy(image, minenergyindex, j, width, height);
				minenergyright = energy(image, minenergyindex - 1, j, width, height);
				minenergyleft = energy(image, minenergyindex + 1, j, width, height);
				if (minenergy <= minenergyright && minenergy <= minenergyleft) {
					seam[j] = minenergyindex;
				}
				else if (minenergyleft <= minenergy && minenergyleft <= minenergyright) {
					minenergyindex += 1;
					seam[j] = minenergyindex;
				}
				else {
					minenergyindex -= 1;
					seam[j] = minenergyindex;
				}
			}
			else if (minenergyindex == 0) {
				minenergy = energy(image, minenergyindex, j, width, height);
				minenergyleft = energy(image, minenergyindex + 1, j, width, height);
				if (minenergy <= minenergyleft) {
					seam[j] = minenergyindex;
				}
				else {
					minenergyindex += 1;
					seam[j] = minenergyindex;
				}
			}
			else {
				minenergy = energy(image, minenergyindex, j, width, height);
				minenergyright = energy(image, minenergyindex - 1, j, width, height); 
				if (minenergy <= minenergyright) {
					seam[j] = minenergyindex;
				}
				else {
					minenergyindex -= 1;
					seam[j] = minenergyindex; 
				}
			}
		}
		else {
			seam[j] = minenergyindex;
		}
		seamenergy += energy(image, minenergyindex, j, width, height);
	}
	return seamenergy;
}


int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
	int seamenergy = 0;
	int minenergy = 0;
	int minenergytop = 0;
	int minenergybot = 0;
	int minenergyindex = start_row;
	for (int j = 0; j < width; ++j) { 
		if (j > 0) {
			if (minenergyindex > 0 && minenergyindex < height - 1) {
				minenergy = energy(image, j, minenergyindex, width, height);
				minenergytop = energy(image, j, minenergyindex - 1, width, height);
				minenergybot = energy(image, j, minenergyindex + 1, width, height);
				if (minenergy <= minenergybot && minenergy <= minenergytop) {
					seam[j] = minenergyindex;
				}
				else if (minenergytop <= minenergy && minenergytop <= minenergybot) {
					minenergyindex -= 1;
					seam[j] = minenergyindex;
				}
				else {
					minenergyindex += 1;
					seam[j] = minenergyindex;
				}
			}
			else if (minenergyindex == 0) {
				minenergy = energy(image, j, minenergyindex, width, height);
				minenergybot = energy(image, j, minenergyindex + 1, width, height);
				if (minenergy <= minenergybot) {
					seam[j] = minenergyindex;
				}
				else {
					minenergyindex += 1;
					seam[j] = minenergyindex;
				}
			}
			else {
				minenergy = energy(image, minenergyindex, j, width, height);
				minenergytop = energy(image, j, minenergyindex - 1, width, height); 
				if (minenergy <= minenergytop) {
					seam[j] = minenergyindex;
				}
				else {
					minenergyindex -= 1;
					seam[j] = minenergyindex; 
				}
			}
		}
		else {
			seam[j] = minenergyindex;
		}
		seamenergy += energy(image, j, minenergyindex, width, height);
	}
	return seamenergy;
}


int* findMinVerticalSeam(Pixel** image, int width, int height) {
	int minenergy = 0;
	int minenergy1 = 0;
	int minenergyindex = 0;
	int* seam = createSeam(height);
	for (int i = 0; i < width; ++i) {
		minenergy1 = loadVerticalSeam(image, i, width, height, seam);
		if (i == 0) {
			minenergy = minenergy1;
			minenergyindex = i;
		}
		if (minenergy1 < minenergy) {
			minenergy = minenergy1;
			minenergyindex = i;
		}
	}
	loadVerticalSeam(image, minenergyindex, width, height, seam);
	return seam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
	int* seam = createSeam(width);
	int minenergy = 0;
	int minenergy1 = 0;
	int minenergyindex = 0;
	for (int k = 0; k < height; ++k) {
		minenergy1 = loadHorizontalSeam(image, k, width, height, seam);
		if (k == 0) {
			minenergy = minenergy1;
			minenergyindex = k;
		}
		if (minenergy1 < minenergy) {
			minenergy = minenergy1;
			minenergyindex = k;
		}
	}
	loadHorizontalSeam(image, minenergyindex, width, height, seam);
	return seam;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
	for (int i = 0; i < height; ++i) {
		for (int j = verticalSeam[i]; j < width - 1; ++j) {
			image[j][i] = image[j+1][i];
		}
	}
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
	for (int i = 0; i < width; ++i) {
		for (int j = horizontalSeam[i]; j < height - 1; ++j) {
			image[i][j] = image[i][j+1];
		}
	}
}
