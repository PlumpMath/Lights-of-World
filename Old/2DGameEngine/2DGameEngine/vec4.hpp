#pragma once

#include <iostream>

namespace engine { namespace maths {

	struct vec4
	{
		float x, y, z, w;

		// Construtor;
		vec4();
		vec4(const float& x, const float& y, const float& z, const float& w);

		// Matematica, Operacoes basicas;
		friend vec4 operator + (vec4 vector, const vec4& other_vector);
		friend vec4 operator - (vec4 vector, const vec4& other_vector);
		friend vec4 operator * (vec4 vector, const vec4& other_vector);
		friend vec4 operator / (vec4 vector, const vec4& other_vector);

		// Matematica, Conversao de operacoes para vetores;
		friend vec4 operator + (vec4 vector, const float& float_number);
		friend vec4 operator - (vec4 vector, const float& float_number);
		friend vec4 operator * (vec4 vector, const float& float_number);
		friend vec4 operator / (vec4 vector, const float& float_number);

		// Iguala a operacao;
		vec4& operator += (const vec4& vector);
		vec4& operator -= (const vec4& vector);
		vec4& operator *= (const vec4& vector);
		vec4& operator /= (const vec4& vector);

		// Comparacao entre vetores;
		bool operator < (const vec4& vector);
		bool operator > (const vec4& vector);

		bool operator == (const vec4& vector);
		bool operator != (const vec4& vector);
		bool operator <= (const vec4& vector);
		bool operator >= (const vec4& vector);

		// Saida;
		friend std::ostream& operator << (std::ostream& stream, const vec4& vector);
	};
} }