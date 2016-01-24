//
//  image.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 25/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <glfw/glfw3.h>

namespace image_loader {
	std::vector<unsigned char> loadImage(const char* file, int* width, int* height);
}

#endif // _IMAGE_HPP_