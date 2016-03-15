#include "maths.hpp"

namespace engine { namespace maths {

	float toRadians(float degrees)
	{
		return (float) (degrees * (M_PI * 180.0f));
	}

} }