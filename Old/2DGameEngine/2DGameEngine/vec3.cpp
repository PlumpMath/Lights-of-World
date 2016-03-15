#include "vec3.hpp"

namespace engine { namespace maths {

	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	// Operadores Matematicos;
	vec3 operator - (vec3 vector, const vec3& other_vector)
	{
		return vec3(vector.x - other_vector.x, vector.y - other_vector.y, vector.z - vector.z);
	}

	vec3 operator * (vec3 vector, const vec3& other_vector)
	{
		return vec3(vector.x * other_vector.x, vector.y * other_vector.y, vector.z * vector.z);
	}

	vec3 operator / (vec3 vector, const vec3& other_vector)
	{
		return vec3(vector.x / other_vector.x, vector.y / other_vector.y, vector.z / vector.z);
	}

	vec3 operator + (vec3 vector, const float& float_number)
	{
		return vector + vec3(float_number, float_number, float_number);
	}

	vec3 operator - (vec3 vector, const float& float_number)
	{
		return vector - vec3(float_number, float_number, float_number);
	}

	vec3 operator * (vec3 vector, const float& float_number)
	{
		return vector * vec3(float_number, float_number, float_number);
	}

	vec3 operator / (vec3 vector, const float& float_number)
	{
		return vector / vec3(float_number, float_number, float_number);
	}

	// Igualacao;
	vec3& vec3::operator += (const vec3& vector)
	{
		return (*this + vector); 
	}

	vec3& vec3::operator -= (const vec3& vector)
	{
		return (*this - vector);
	}

	vec3& vec3::operator *= (const vec3& vector)
	{
		return (*this * vector);
	}

	vec3& vec3::operator /= (const vec3& vector)
	{
		return (*this / vector);
	}

	// Comparacao;
	bool vec3::operator == (const vec3& vector)
	{
		return (this->x == vector.x && this->y == vector.y && this->z == vector.z);
	}
	
	bool vec3::operator != (const vec3& vector)
	{
		return !(*this == vector);
	}

	bool vec3::operator <= (const vec3& vector)
	{
		return (this->x <= vector.x && this->y <= vector.y && this->z <= vector.z);
	}

	bool vec3::operator >= (const vec3& vector)
	{
		return !(*this <= vector);
	}

	bool vec3::operator < (const vec3& vector)
	{
		return (this->x < vector.x && this->y < vector.y && this->z < vector.z);
	}

	bool vec3::operator > (const vec3& vector)
	{
		return !(*this < vector);
	}

	// Saida;
	std::ostream& operator << (std::ostream& stream, const vec3& vector)
	{
		stream << "<Vector3 (" << vector.x << ", " << vector.y << ", " << vector.z << ")>";
		return stream;
	}
} }