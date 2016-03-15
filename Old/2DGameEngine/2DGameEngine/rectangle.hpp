#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "maths.hpp"

namespace engine { using namespace maths; namespace graphics {

	class KX_ScreenRect
	{
	public:
		vec4 coordinates;

		KX_ScreenRect(float x=0.0f, float y=0.0f, float w=0.0f, float h=0.0f);
		~KX_ScreenRect() {};

		// Retornos dos parametros;
		inline float top() { return coordinates.y; };
		inline float left() { return coordinates.x; };

		inline float right() { return coordinates.y + coordinates.w; };
		inline float bottom() { return coordinates.x + coordinates.z; };
	};

	class KX_WorldRect : public KX_ScreenRect
	{
	public:
		KX_WorldRect(float x=0.0f, float y=0.0f, float w=0.0f, float h=0.0f);
		~KX_WorldRect() {};

		// Retornos dos parametros;
		inline float top() { return coordinates.y + coordinates.w; };
		inline float left() { return coordinates.x; };

		inline float right() { return coordinates.x + coordinates.z; };
		inline float bottom() { return coordinates.y; };
	};

} }

#endif // __RECTANGLE_HPP__