#include "vec2.hpp"

namespace engine { namespace maths {
    
    vec2::vec2(const float& x, const float& y)
    {
        this->x = x;
        this->y = y;
    }
    
    vec2& vec2::add(const vec2& vector)
    {
        x += vector.x;
        y += vector.y;
        
        return *this;
    }
    
    vec2& vec2::subtract(const vec2& vector)
    {
        x -= vector.x;
        y -= vector.y;
        
        return *this;
    }
    
    vec2& vec2::multiply(const vec2& vector)
    {
        x *= vector.x;
        y *= vector.y;
        
        return *this;
    }
    
    vec2& vec2::divide(const vec2& vector)
    {
        x /= vector.x;
        y /= vector.y;
        
        return *this;
    }
    
    bool vec2::compare(const vec2& vector)
    {
        return x == vector.x && y == vector.y;
    }
    
    vec2 operator+(vec2 vector, const vec2& other_vector)
    {
        return vector.add(other_vector);
    }
    
    vec2 operator-(vec2 vector, const vec2& other_vector)
    {
        return vector.subtract(other_vector);
    }
    
    vec2 operator*(vec2 vector, const vec2& other_vector)
    {
        return vector.multiply(other_vector);
    }
    
    vec2 operator/(vec2 vector, const vec2& other_vector)
    {
        return vector.divide(other_vector);
    }
    
    vec2 operator+(vec2 vector, const float other_vector)
    {
        return vector + vec2((float) other_vector, (float) other_vector);
    }
    
    vec2 operator-(vec2 vector, const float other_vector)
    {
        return vector - vec2((float) other_vector, (float) other_vector);
    }
    
    vec2 operator*(vec2 vector, const float other_vector)
    {
        return vector * vec2((float) other_vector, (float) other_vector);
    }
    
    vec2 operator/(vec2 vector, const float other_vector)
    {
        return vector / vec2((float) other_vector, (float) other_vector);
    }
    
    vec2& vec2::operator+=(const vec2& vector)
    {
        return add(vector);
    }
    
    vec2& vec2::operator-=(const vec2& vector)
    {
        return subtract(vector);
    }
    
    vec2& vec2::operator*=(const vec2& vector)
    {
        return multiply(vector);
    }
    
    vec2& vec2::operator/=(const vec2& vector)
    {
        return divide(vector);
    }
    
    bool vec2::operator==(const vec2& vector)
    {
        return compare(vector);
    }
    
    bool vec2::operator!=(const vec2& vector)
    {
        return !(*this == vector);
    }
    
    std::ostream& operator<<(std::ostream& stream, const vec2& vector)
    {
        stream << "<Vector2 (" << vector.x << ", " << vector.y << ")>";
        return stream;
    }
} }