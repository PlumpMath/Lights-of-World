/*
	SincroB Vetor2;
*/
#pragma once
#include <iostream>

namespace engine { namespace maths {

	struct vec2
	{
		float x, y;

		// Construtor;
		vec2();
		vec2(const float& x, const float& y);

		// Matematica, Operacoes basicas;
		friend vec2 operator + (vec2 vector, const vec2& other_vector);
		friend vec2 operator - (vec2 vector, const vec2& other_vector);
		friend vec2 operator * (vec2 vector, const vec2& other_vector);
		friend vec2 operator / (vec2 vector, const vec2& other_vector);

		// Matematica, Conversao de operacoes para vetores;
		friend vec2 operator + (vec2 vector, const float& float_number);
		friend vec2 operator - (vec2 vector, const float& float_number);
		friend vec2 operator * (vec2 vector, const float& float_number);
		friend vec2 operator / (vec2 vector, const float& float_number);

		// Iguala a operacao;
		vec2& operator += (const vec2& vector);
		vec2& operator -= (const vec2& vector);
		vec2& operator *= (const vec2& vector);
		vec2& operator /= (const vec2& vector);

		// Comparacao entre vetores;
		bool operator < (const vec2& vector);
		bool operator > (const vec2& vector);

		bool operator == (const vec2& vector);
		bool operator != (const vec2& vector);
		bool operator <= (const vec2& vector);
		bool operator >= (const vec2& vector);

		// Saida;
		friend std::ostream& operator << (std::ostream& stream, const vec2& vector);
	};
} }