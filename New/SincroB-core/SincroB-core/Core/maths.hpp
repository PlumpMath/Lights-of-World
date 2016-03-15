#pragma once

// Inclusão e definição matemática; (Assim eu consigo usar o macro M_PI)
#define _USE_MATH_DEFINES
#include <math.h>

// Inclusão dos vetores;
#include "maths/vec2.hpp"
#include "maths/vec3.hpp"
#include "maths/vec4.hpp"

// Inclusão da matrix;
#include "maths/mat4.hpp"

namespace engine { namespace maths {
   
    float toRadians(float degrees);
    
} }