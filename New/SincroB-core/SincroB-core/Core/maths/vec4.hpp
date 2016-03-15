#pragma once

#include <iostream>

namespace engine { namespace maths {
  
    struct vec4
    {
        float x, y, z, w;
        
        vec4() = default;
        vec4(const float& x, const float& y, const float& z, const float& w);
        
        vec4& add(const vec4& vector);
        vec4& subtract(const vec4& vector);
        vec4& multiply(const vec4& vector);
        vec4& divide(const vec4& vector);
        bool compare(const vec4& vector);
        
        friend vec4 operator+(vec4 vector, const vec4& other_vector);
        friend vec4 operator-(vec4 vector, const vec4& other_vector);
        friend vec4 operator*(vec4 vector, const vec4& other_vector);
        friend vec4 operator/(vec4 vector, const vec4& other_vector);

        friend vec4 operator+(vec4 vector, const float other_vector);
        friend vec4 operator-(vec4 vector, const float other_vector);
        friend vec4 operator*(vec4 vector, const float other_vector);
        friend vec4 operator/(vec4 vector, const float other_vector);

        vec4& operator+=(const vec4& vector);
        vec4& operator-=(const vec4& vector);
        vec4& operator*=(const vec4& vector);
        vec4& operator/=(const vec4& vector);
        
        bool operator==(const vec4& vector);
        bool operator!=(const vec4& vector);
        
        friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
    };

} }