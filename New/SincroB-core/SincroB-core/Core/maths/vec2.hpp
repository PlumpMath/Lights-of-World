#pragma once

#include <iostream>

namespace engine { namespace maths {
  
    struct vec2
    {
        float x, y;
        
        vec2() = default;
        vec2(const float& x, const float& y);
        
        vec2& add(const vec2& vector);
        vec2& subtract(const vec2& vector);
        vec2& multiply(const vec2& vector);
        vec2& divide(const vec2& vector);
        bool compare(const vec2& vector);
        
        friend vec2 operator+(vec2 vector, const vec2& other_vector);
        friend vec2 operator-(vec2 vector, const vec2& other_vector);
        friend vec2 operator*(vec2 vector, const vec2& other_vector);
        friend vec2 operator/(vec2 vector, const vec2& other_vector);
        
        friend vec2 operator+(vec2 vector, const float other_vector);
        friend vec2 operator-(vec2 vector, const float other_vector);
        friend vec2 operator*(vec2 vector, const float other_vector);
        friend vec2 operator/(vec2 vector, const float other_vector);
        
        vec2& operator+=(const vec2& vector);
        vec2& operator-=(const vec2& vector);
        vec2& operator*=(const vec2& vector);
        vec2& operator/=(const vec2& vector);
        
        bool operator==(const vec2& vector);
        bool operator!=(const vec2& vector);
        
        friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
    };
} }