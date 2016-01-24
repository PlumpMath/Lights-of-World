//
//  image.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 25/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <iostream>

#include "lodepng.h"
#include "image.hpp"

std::vector<unsigned char> loadImage(const char* file, int* width, int* height) {

	// Load file and decode image.
	std::vector<unsigned char> image;

	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, file);

	int screenw = width;
	if(screenw > 1024) screenw = 1024;
	int screenh = height;
	if(screenh > 768) screenw = 768;

	size_t u2 = 1; while(u2 < width) u2 *= 2;
	size_t v2 = 1; while(v2 < height) v2 *= 2;
	// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
	double u3 = (double) width / u2;
	double v3 = (double) height / v2;

	// Make power of two version of the image.
	std::vector<unsigned char> image2(u2 * v2 * 4);
	for(size_t y = 0; y < height; y++)
	for(size_t x = 0; x < width; x++)
	for(size_t c = 0; c < 4; c++) {
    image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
	}

	return image2;
}