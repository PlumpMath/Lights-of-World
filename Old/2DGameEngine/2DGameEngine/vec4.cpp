#include "vec4.hpp"

namespace engine { namespace maths {

	vec4::vec4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	// Operadores Matematicos;
	vec4 operator - (vec4 vector, const vec4& other_vector)
	{
		return vec4(vector.x - other_vector.x, vector.y - other_vector.y, vector.z - other_vector.z, vector.w - other_vector.w);
	}

	vec4 operator * (vec4 vector, const vec4& other_vector)
	{
		return vec4(vector.x * other_vector.x, vector.y * other_vector.y, vector.z * other_vector.z, vector.w * other_vector.w);
	}

	vec4 operator / (vec4 vector, const vec4& other_vector)
	{
		return vec4(vector.x / other_vector.x, vector.y / other_vector.y, vector.z / other_vector.z, vector.w / other_vector.w);
	}

	vec4 operator + (vec4 vector, const float& float_number)
	{
		return vector + vec4(float_number, float_number, float_number, float_number);
	}

	vec4 operator - (vec4 vector, const float& float_number)
	{
		return vector - vec4(float_number, float_number, float_number, float_number);
	}

	vec4 operator * (vec4 vector, const float& float_number)
	{
		return vector * vec4(float_number, float_number, float_number, float_number);
	}

	vec4 operator / (vec4 vector, const float& float_number)
	{
		return vector / vec4(float_number, float_number, float_number, float_number);
	}

	// Igualacao;
	vec4& vec4::operator += (const vec4& vector)
	{
		return (*this + vector); 
	}

	vec4& vec4::operator -= (const vec4& vector)
	{
		return (*this - vector);
	}

	vec4& vec4::operator *= (const vec4& vector)
	{
		return (*this * vector);
	}

	vec4& vec4::operator /= (const vec4& vector)
	{
		return (*this / vector);
	}

	// Comparacao;
	bool vec4::operator == (const vec4& vector)
	{
		return (this->x == vector.x && this->y == vector.y && this->z == vector.z && this->w == vector.w);
	}
	
	bool vec4::operator != (const vec4& vector)
	{
		return !(*this == vector);
	}

	bool vec4::operator <= (const vec4& vector)
	{
		return (this->x <= vector.x && this->y <= vector.y && this->z <= vector.z && this->w <= vector.w);
	}

	bool vec4::operator >= (const vec4& vector)
	{
		return !(*this <= vector);
	}

	bool vec4::operator < (const vec4& vector)
	{
		return (this->x < vector.x && this->y < vector.y && this->z < vector.z && this->w < vector.w);
	}

	bool vec4::operator > (const vec4& vector)
	{
		return !(*this < vector);
	}

	// Saida;
	std::ostream& operator << (std::ostream& stream, const vec4& vector)
	{
		stream << "<Vector4 (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")>";
		return stream;
	}
} }