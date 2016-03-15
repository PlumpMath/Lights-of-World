#ifndef __COLLISIONS_HPP__
#define __COLLISIONS_HPP__

#include "maths.hpp"

namespace engine { using namespace maths; namespace graphics {
   
#define GRAVITY 9.8f
    
    struct Object;
    struct Rect;
    struct Scene;
    
    struct CollisionNormal
    {
        CollisionNormal() {};
        ~CollisionNormal() {};
        
        bool left   = false;
        bool right  = false;
        bool top    = false;
        bool bottom = false;
        
        friend std::ostream& operator << (std::ostream& stream, const CollisionNormal& collision)
        {
            stream << "<CollisionNormal {left:" << collision.left << ", right:" << collision.right << ", top:" << collision.top << ", bottom:" << collision.bottom << "}>";
            return stream;
        }
    };
    
    struct CollisionVector
    {
        inline CollisionVector() { minus_x=false; minus_y=false; plus_x=false; plus_y=false; };
        ~CollisionVector() {};
        
        bool minus_x, minus_y;
        bool plus_x, plus_y;
        
        friend std::ostream& operator << (std::ostream& stream, const CollisionVector& collision)
        {
            stream << "<CollisionVector {minus_x:" << collision.minus_x << ", minus_y:" << collision.minus_y << "} {plus_x:" << collision.plus_x << ", plus_y:" << collision.plus_y << "}>";
            return stream;
        }
    };
    
    class Collision
    {
    public:
        Collision(Object* object) { this->collisionObject = object; };
        ~Collision() {};
        Object* collisionObject;
    private:
        // Detecções de Colisão;
        bool collided_bottom, collided_top;
        bool collided_left, collided_right;
        
        vec2 linearVelocity;
        vec2 Velocity;
        vec2 Force;
        
    public:
        void update();
        
        CollisionNormal detect_fac_collision(Object* other); // Retorna a face em colisão;
        CollisionVector detect_nrm_collision(Object* other); // Retorna as colisões do eixo (X e -X, Y e -Y)
        
        bool detect_collision(Object* other);
    };
    
    struct CollisionIntersection
    {
        CollisionIntersection(Collision* collision);
        ~CollisionIntersection();
        
        Rect* Rectangle;
        bool RectangleDraw=false;
        void drawIntersection(Scene& scene);
        
        Collision* collision;
        
        vec3 xIntersection;
        vec3 yIntersection;
        
        // Captura da Intersecção;
        virtual void getIntersection(Object* other);
    };
    
} }

#endif // __COLLISIONS_HPP__