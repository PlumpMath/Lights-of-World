#include "vec4.hpp"

namespace engine { namespace maths {
    
    vec4::vec4(const float& x, const float& y, const float& z, const float& w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
    
    vec4& vec4::add(const vec4& vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        w += vector.w;
        
        return *this;
    }
    
    vec4& vec4::subtract(const vec4& vector)
    {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        w -= vector.w;
        
        return *this;
    }
    
    vec4& vec4::multiply(const vec4& vector)
    {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
        w *= vector.w;
        
        return *this;
    }
    
    vec4& vec4::divide(const vec4& vector)
    {
        x /= vector.x;
        y /= vector.y;
        z /= vector.z;
        w /= vector.w;
        
        return *this;
    }
    
    bool vec4::compare(const vec4& vector)
    {
        return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
    }
    
    vec4 operator+(vec4 vector, const vec4& other_vector)
    {
        return vector.add(other_vector);
    }
    
    vec4 operator-(vec4 vector, const vec4& other_vector)
    {
        return vector.subtract(other_vector);
    }
    
    vec4 operator*(vec4 vector, const vec4& other_vector)
    {
        return vector.multiply(other_vector);
    }
    
    vec4 operator/(vec4 vector, const vec4& other_vector)
    {
        return vector.divide(other_vector);
    }
    
    vec4 operator+(vec4 vector, const float other_vector)
    {
        return vector + vec4((float) other_vector,(float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec4 operator-(vec4 vector, const float other_vector)
    {
        return vector - vec4((float) other_vector,(float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec4 operator*(vec4 vector, const float other_vector)
    {
        return vector * vec4((float) other_vector,(float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec4 operator/(vec4 vector, const float other_vector)
    {
        return vector / vec4((float) other_vector,(float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec4& vec4::operator+=(const vec4& vector)
    {
        return add(vector);
    }
    
    vec4& vec4::operator-=(const vec4& vector)
    {
        return subtract(vector);
    }
    
    vec4& vec4::operator*=(const vec4& vector)
    {
        return multiply(vector);
    }
    
    vec4& vec4::operator/=(const vec4& vector)
    {
        return divide(vector);
    }
    
    bool vec4::operator==(const vec4& vector)
    {
        return compare(vector);
    }
    
    bool vec4::operator!=(const vec4& vector)
    {
        return !(*this == vector);
    }
    
    std::ostream& operator<<(std::ostream& stream, const vec4& vector)
    {
        stream << "<Vector4 (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")>";
        return stream;
    }
} }