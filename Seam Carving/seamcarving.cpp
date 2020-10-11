#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
  string filename;
  int width = 0;
  int height = 0;
  int targetWidth = 0;
  int targetHeight = 0;
  
  // Add code to validate input (Do in part 1)
  cout << "Input filename: ";
  cin >> filename;
  cout << "Input width and height: ";
  cin >> width;
  if(cin.fail()) {
	cout << "Error: width is a non-integer value" << endl;
	return 0;
  }
  cin >> height;
  if(cin.fail()) {
	cout << "Error: height is a non-integer value" << endl;
	return 0;
  }
  cout << "Input target width and target height: ";
  cin >> targetWidth;
  if(cin.fail()) {
	cout << "Error: target width is a non-integer value" << endl;
	return 0;
  }
  cin >> targetHeight;
  if(cin.fail()) {
	cout << "Error: target height is a non-integer value" << endl;
	return 0;
  }
  // Error check
  if (width <= 0 || height <= 0) {
		if (width < 0) {
			cout << "Error: width must be greater than 0. You entered " << width << endl;
		}
		else if (width == 0) {
			cout << "Error: width must be greater than 0. You entered 0" << endl;
		}
		else if (height < 0) {
			cout << "Error: height must be greater than 0. You entered " << height << endl;
		}
		else if (height == 0) {
			cout << "Error: height must be greater than 0. You entered 0" << endl;
		}
	return 0;
  }
  if (targetWidth <= 0 || targetHeight <= 0) {
		if (targetWidth < 0) {
			cout << "Error: target width must be greater than 0. You entered " << targetWidth << endl;
		}
		else if (targetWidth == 0) {
			cout << "Error: target width must be greater than 0. You entered 0" << endl;
		}
		else if (targetHeight < 0) {
			cout << "Error: target height must be greater than 0. You entered " << targetHeight << endl;
		}
		else if (targetHeight == 0) {
			cout << "Error: target height must be greater than 0. You entered 0" << endl;
		}
	return 0;
  }
  if (targetWidth > width || targetHeight > height) {
	  if (targetWidth > width) {
		  cout << "Error: target width must be less than width, " << targetWidth << " is greater than " << width << endl;
	  }
	  else {
		  cout << "Error: target height must be less than height, " << targetHeight << " is greater than " << height << endl;
	  }
	 return 0;
  }
  int originalWidth = width; // need to delete image array at end of program
  Pixel** image = createImage(width, height); // create array of size that we need
  if (image != nullptr) {
    if (loadImage(filename, image, width, height)) {
      cout << "Start carving..." << endl;
	
	  while ((width > targetWidth) || (height > targetHeight)) {
		if (width > targetWidth) {
			int* Vert = findMinVerticalSeam(image, width, height);
			removeVerticalSeam(image, width, height, Vert);
			width -= 1;
		}
		if (height > targetHeight) {
			int* Horz = findMinHorizontalSeam(image, width, height);
			removeHorizontalSeam(image, width, height, Horz);
			height -= 1;
		}
	  }
      stringstream ss;
      ss << "carved" << width << "X" << height << "." << filename;
      outputImage(ss.str().c_str(), image, width, height);
  
    // call last to remove the memory from the heap
    deleteImage(image, originalWidth);
	}
  }
  return 0;
}