#pragma once

#include "maths.hpp"
#include <iostream>

namespace engine { namespace maths {

	struct matcol
	{
		float x, y, z, w;

		vec2 vector2() { vec2 result(x, y); return result; }
		vec3 vector3() { vec3 result(x, y, z); return result; }
		vec4 vector4() { vec4 result(x, y, z, w); return result; }

		friend std::ostream& operator << (std::ostream& stream, const matcol& matrix)
		{
			stream << "<Matrix4x4 Column (" << matrix.x << ", " << matrix.y << ", " << matrix.z << ", " << matrix.w << ")>";
			return stream;
		}
	};

	struct mat4
	{
		// Criacao de colunas; // Nao consegui usar os vetores para o union, pelo construtor nao ser default;
		union { float elements[4 * 4]; matcol columns[4]; };

		mat4();
		mat4(float diagonal);

		// Metodos estáticos;
		static mat4 identity();

		static mat4 ortographic(float left, float top, float right, float bottom, float near, float far);
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);

		// Operacões;
		mat4& multiply(const mat4& other);

		friend mat4 operator * (mat4 matrix, const mat4& other_matrix);

		mat4& operator *= (const mat4& matrix);
		
		friend std::ostream& operator << (std::ostream& stream, const mat4& matrix);
	};
} }