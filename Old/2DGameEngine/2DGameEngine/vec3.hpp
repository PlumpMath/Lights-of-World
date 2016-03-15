/*
	SincroB Vetor2;
*/
#pragma once
#include <iostream>

namespace engine { namespace maths {

	struct vec3
	{
		float x, y, z;

		// Construtor;
		vec3();
		vec3(const float& x, const float& y, const float& z);

		// Matematica, Operacoes basicas;
		friend vec3 operator + (vec3 vector, const vec3& other_vector);
		friend vec3 operator - (vec3 vector, const vec3& other_vector);
		friend vec3 operator * (vec3 vector, const vec3& other_vector);
		friend vec3 operator / (vec3 vector, const vec3& other_vector);

		// Matematica, Conversao de operacoes para vetores;
		friend vec3 operator + (vec3 vector, const float& float_number);
		friend vec3 operator - (vec3 vector, const float& float_number);
		friend vec3 operator * (vec3 vector, const float& float_number);
		friend vec3 operator / (vec3 vector, const float& float_number);

		// Iguala a operacao;
		vec3& operator += (const vec3& vector);
		vec3& operator -= (const vec3& vector);
		vec3& operator *= (const vec3& vector);
		vec3& operator /= (const vec3& vector);

		// Comparacao entre vetores;
		bool operator < (const vec3& vector);
		bool operator > (const vec3& vector);

		bool operator == (const vec3& vector);
		bool operator != (const vec3& vector);
		bool operator <= (const vec3& vector);
		bool operator >= (const vec3& vector);

		// Saida;
		friend std::ostream& operator << (std::ostream& stream, const vec3& vector);
	};
} }