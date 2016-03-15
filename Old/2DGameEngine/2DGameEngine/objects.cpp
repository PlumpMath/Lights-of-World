#include "objects.hpp"

namespace engine { using namespace maths; namespace graphics {

	KX_StaticObject::KX_StaticObject(const vec2& position, const vec2& scale)
	{
		localPosition = position;
		localScale = scale;
	}

	KX_MovingObject::KX_MovingObject(const vec2& position, const vec2& scale)
	{
		localPosition = position;
		localScale = scale;
	}

} }