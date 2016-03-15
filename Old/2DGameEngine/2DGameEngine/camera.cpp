#include "camera.hpp"

namespace engine { using namespace maths; namespace graphics {

	KX_Camera::KX_Camera()
	{
		vecTarget = NULL;
		inTarget = false;

		scale = 1.0f;
		aspect = 0.0f;
		
		// Posicao inicial;
		move.x = 0.0f; move.y = 0.0f;
	}

	void KX_Camera::init(int x, int y, int width, int height)
	{
		localPosition.x = (float) x;
		localPosition.y = (float) y;

		localScale.x = (float) width;
		localScale.y = (float) height;

		Velocity = vec2(0.0f, 0.0f);
	}

	void KX_Camera::setOrthoMatrix()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho((int) localPosition.x, (int) localPosition.x + (int) localScale.x,
				(int) localPosition.y, (int) localPosition.y + (int) localScale.y, -1.0f, 0.0f);
	}

	void KX_Camera::reshapeCamera(const float& width, const float& height)
	{
		float dw = width - localScale.x;
		float dh = height - localScale.y;

		float cx = localPosition.x + localScale.x / 2;
		float cy = localPosition.y + localScale.y / 2;

		localScale.x += dw;
		localScale.y += dh;

		localPosition.x = cx - localScale.x / 2;
		localPosition.y = cy - localScale.y / 2;
	}

	void KX_Camera::moveToTarget()
	{
		localPosition = vecTarget->localPosition + vecTarget->localScale * 0.5f - localScale * 0.5f;
	}

} }