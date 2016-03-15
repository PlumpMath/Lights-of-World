#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__

#include "maths.hpp"

namespace engine { using namespace maths; namespace graphics {

	class KX_StaticObject
	{
	public:
		KX_StaticObject(const vec2& position=vec2(0.0f, 0.0f), const vec2& scale=vec2(0.0f, 0.0f));
		~KX_StaticObject();

		vec2 localPosition;
		vec2 localScale;
	};

	class KX_MovingObject : public KX_StaticObject
	{
	public:
		KX_MovingObject(const vec2& position=vec2(0.0f, 0.0f), const vec2& scale=vec2(0.0f, 0.0f));
		~KX_MovingObject();

		vec2 lastPosition;
		vec2 lastVelocity;
		vec2 Velocity;
	};
} }

#endif // __OBJECTS_HPP__