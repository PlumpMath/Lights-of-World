#include "vec3.hpp"

namespace engine { namespace maths {
    
    vec3::vec3(const float& x, const float& y, const float& z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    vec3& vec3::add(const vec3& vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        
        return *this;
    }
    
    vec3& vec3::subtract(const vec3& vector)
    {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        
        return *this;
    }
    
    vec3& vec3::multiply(const vec3& vector)
    {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
        
        return *this;
    }
    
    vec3& vec3::divide(const vec3& vector)
    {
        x /= vector.x;
        y /= vector.y;
        z /= vector.z;
        
        return *this;
    }
    
    bool vec3::compare(const vec3& vector)
    {
        return x == vector.x && y == vector.y && z == vector.z;
    }
    
    vec3 operator+(vec3 vector, const vec3& other_vector)
    {
        return vector.add(other_vector);
    }
    
    vec3 operator-(vec3 vector, const vec3& other_vector)
    {
        return vector.subtract(other_vector);
    }
    
    vec3 operator*(vec3 vector, const vec3& other_vector)
    {
        return vector.multiply(other_vector);
    }
    
    vec3 operator/(vec3 vector, const vec3& other_vector)
    {
        return vector.divide(other_vector);
    }
    
    vec3 operator+(vec3 vector, const float other_vector)
    {
        return vector + vec3((float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec3 operator-(vec3 vector, const float other_vector)
    {
        return vector - vec3((float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec3 operator*(vec3 vector, const float other_vector)
    {
        return vector * vec3((float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec3 operator/(vec3 vector, const float other_vector)
    {
        return vector / vec3((float) other_vector,(float) other_vector,(float) other_vector);
    }
    
    vec3& vec3::operator+=(const vec3& vector)
    {
        return add(vector);
    }
    
    vec3& vec3::operator-=(const vec3& vector)
    {
        return subtract(vector);
    }
    
    vec3& vec3::operator*=(const vec3& vector)
    {
        return multiply(vector);
    }
    
    vec3& vec3::operator/=(const vec3& vector)
    {
        return divide(vector);
    }
    
    bool vec3::operator==(const vec3& vector)
    {
        return compare(vector);
    }
    
    bool vec3::operator!=(const vec3& vector)
    {
        return !(*this == vector);
    }
    
    std::ostream& operator<<(std::ostream& stream, const vec3& vector)
    {
        stream << "<Vector3 (" << vector.x << ", " << vector.y << ", " << vector.z << ")>";
        return stream;
    }
} }