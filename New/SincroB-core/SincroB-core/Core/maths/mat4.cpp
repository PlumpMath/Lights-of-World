#include "mat4.hpp"

namespace engine { namespace maths {

	// Matrix;
	mat4::mat4()
	{
		for (int idx = 0; idx < 4 * 4; idx++)
			elements[idx] = 0.0f;
	}

	mat4::mat4(float diagonal)
	{
		for (int idx = 0; idx < 4 * 4; idx++)
		{
			if (idx < 4)
				elements[idx + idx * 4] = diagonal;

			if (elements[idx] != diagonal)
				elements[idx] = 0.0f;
		}
	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	mat4 mat4::ortographic(float left, float top, float right, float bottom, float near, float far)
	{
		mat4 result(1.0f);

		float properties[6] = {right, left, top, bottom, near, far};

		// Edicao de elementos nas colunas [0, 1, 2];
		for (int idx = 0; idx < 4 - 1; idx++)
			result.elements[idx + idx * 4] = 2 / (properties[idx * 2] - properties[idx * 2 + 1]);

		properties[4] = far;
		properties[5] = near;

		for (int idx = 0; idx < 4 - 1; idx++)
			result.elements[idx + 3 * 4] = (properties[idx * 2] + properties[idx * 2 + 1]) / (properties[idx * 2] - properties[idx * 2 + 1]);

		return result;
	}

	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 result(1.0f);

		float q = 1.0f / tan(toRadians(0.5f * fov));
        float a = q / aspectRatio;
        
        float b = (near + far) / (near - far);
        float c = (2.0f * near * far) / (near - far);

		float properties[5] = {a, q, b, -1.0f, c};

		/*
		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;

		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = c;
		*/

		for (int idx = 0; idx < 4; idx++)
		{
			if (idx == 4 - 1)
			{
				result.elements[idx + (idx - 1) * 4] = properties[idx];
				result.elements[(idx - 1) + idx * 4] = properties[idx + 1];

			} else
				result.elements[idx + idx * 4] = properties[idx];

		}

		return result;
	}

	mat4 mat4::translation(const vec3& translation)
	{
		mat4 result;

		result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;

		return result;
	}

	mat4 mat4::rotation(float angle, const vec3 &axis)
    {
        mat4 result(1.0f);
        
        float r = toRadians(angle);
        float c = cos(r);
        float s = sin(r);
        float omc = 1.0f - c;
        
        float x = axis.x;
        float y = axis.y;
        float z = axis.z;
        
        result.elements[0 + 0 * 4] = x * omc + c;
        result.elements[1 + 0 * 4] = y * x * omc + z * s;
        result.elements[2 + 0 * 4] = x * z * omc - y * s;
        
        result.elements[0 + 1 * 4] = x * y * omc - z * s;
        result.elements[1 + 1 * 4] = y * omc + c;
        result.elements[2 + 1 * 4] = y * z * omc + x * s;
        
        result.elements[0 + 2 * 4] = x * z * omc + y * s;
        result.elements[1 + 2 * 4] = y * z * omc - x * s;
        result.elements[2 + 2 * 4] = z * omc + c;
        
        return result;
    }

	mat4 mat4::scale(const vec3& scale)
	{
		mat4 result;

		result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

	mat4& mat4::multiply(const mat4& matrix)
	{
		mat4 result;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				
				for (int e = 0; e < 4; e++)
				{
					sum += elements[x + e * 4] * matrix.elements[e + y * 4];
				} elements[x + y * 4] = sum;
			}
		}

		return *this;
	}

	mat4 operator * (mat4 matrix, const mat4& other_matrix)
	{
		return matrix.multiply(other_matrix);
	}
	
	mat4& mat4::operator *= (const mat4& matrix)
	{
		return multiply(matrix);
	}

	std::ostream& operator << (std::ostream& stream, const mat4& matrix)
	{
		stream << "<Matrix4x4 ([" << matrix.elements[0] << ", " << matrix.elements[1] << ", " << matrix.elements[2] << ", " << matrix.elements[3] << "]\n"
			               << "[" << matrix.elements[4] << ", " << matrix.elements[5] << ", " << matrix.elements[6] << ", " << matrix.elements[7] << "]\n"
			               << "[" << matrix.elements[8] << ", " << matrix.elements[9] << ", " << matrix.elements[10] << ", " << matrix.elements[11] << "]\n"
						   << "[" << matrix.elements[12] << ", " << matrix.elements[13] << ", " << matrix.elements[14] << ", " << matrix.elements[15] << "])>";

		return stream;
	}
} }