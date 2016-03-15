#include "vec2.hpp"

namespace engine { namespace maths {

	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	// Operadores Matematicos;
	vec2 operator + (vec2 vector, const vec2& other_vector)
	{
		return vec2(vector.x + other_vector.x, vector.y + other_vector.y);
	}

	vec2 operator - (vec2 vector, const vec2& other_vector)
	{
		return vec2(vector.x - other_vector.x, vector.y - other_vector.y);
	}

	vec2 operator * (vec2 vector, const vec2& other_vector)
	{
		return vec2(vector.x * other_vector.x, vector.y * other_vector.y);
	}

	vec2 operator / (vec2 vector, const vec2& other_vector)
	{
		return vec2(vector.x / other_vector.x, vector.y / other_vector.y);
	}

	vec2 operator + (vec2 vector, const float& float_number)
	{
		return vector + vec2(float_number, float_number);
	}

	vec2 operator - (vec2 vector, const float& float_number)
	{
		return vector - vec2(float_number, float_number);
	}

	vec2 operator * (vec2 vector, const float& float_number)
	{
		return vector * vec2(float_number, float_number);
	}

	vec2 operator / (vec2 vector, const float& float_number)
	{
		return vector / vec2(float_number, float_number);
	}

	// Igualacao;
	vec2& vec2::operator += (const vec2& vector)
	{
		return (*this + vector); 
	}

	vec2& vec2::operator -= (const vec2& vector)
	{
		return (*this - vector);
	}

	vec2& vec2::operator *= (const vec2& vector)
	{
		return (*this * vector);
	}

	vec2& vec2::operator /= (const vec2& vector)
	{
		return (*this / vector);
	}

	// Comparacao;
	bool vec2::operator == (const vec2& vector)
	{
		return (this->x == vector.x && this->y == vector.y);
	}
	
	bool vec2::operator != (const vec2& vector)
	{
		return !(*this == vector);
	}

	bool vec2::operator <= (const vec2& vector)
	{
		return (this->x <= vector.x && this->y <= vector.y);
	}

	bool vec2::operator >= (const vec2& vector)
	{
		return !(*this <= vector);
	}

	bool vec2::operator < (const vec2& vector)
	{
		return (this->x < vector.x && this->y < vector.y);
	}

	bool vec2::operator > (const vec2& vector)
	{
		return !(*this < vector);
	}

	// Saida;
	std::ostream& operator << (std::ostream& stream, const vec2& vector)
	{
		stream << "<Vector2 (" << vector.x << ", " << vector.y << ")>";
		return stream;
	}
} }