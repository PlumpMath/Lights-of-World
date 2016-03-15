#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <windows.h>
#include <GL/gl.h>

#include "rectangle.hpp"
#include "objects.hpp"

namespace engine { using namespace maths; namespace graphics {

	class KX_Camera : public KX_MovingObject
	{
	public:
		KX_Camera();
		~KX_Camera();

		void reshapeCamera(const float& width, const float& height);
		void moveToTarget();
		void setOrthoMatrix();

		void init(int x, int y, int width, int height);
		void update(KX_WorldRect* constrains);

	public:
		vec2 move;

		float aspect;
		float scale;

		bool inTarget;
		KX_MovingObject* vecTarget;
	};
} }

#endif // __CAMERA_HPP__