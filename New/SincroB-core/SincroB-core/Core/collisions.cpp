#include "collisions.hpp"
#include "objects.hpp"
#include "rectangle.hpp"

namespace engine { using namespace maths; namespace graphics {

    void Collision::update()
    {
        
    }
    
    CollisionNormal Collision::detect_fac_collision(Object *other)
    {
        CollisionVector collision = detect_nrm_collision(other);
        CollisionNormal collision_nrm;
        
        bool left_right = collision.plus_x || collision.minus_x;
        bool top_down   = collision.plus_y || collision.minus_y;
        
        collision_nrm.top = (left_right && collision.plus_y);
        collision_nrm.bottom = (left_right && collision.minus_y);
        
        collision_nrm.right = (top_down && collision.plus_x);
        collision_nrm.left = (top_down && collision.minus_x);
        
        return collision_nrm;
    }
    
    CollisionVector Collision::detect_nrm_collision(Object* other)
    {
        CollisionVector *collision = new CollisionVector;
        
        collision->minus_y = (collisionObject->localPosition.y <= other->localPosition.y + other->localScale.y);/* &&
                             (collisionObject->localPosition.y >= other->localPosition.y);*/
        
        collision->minus_x = (collisionObject->localPosition.x <= other->localPosition.x + other->localScale.x);/* &&
                             (collisionObject->localPosition.x >= other->localPosition.x);*/
        
        collision->plus_y = (collisionObject->localPosition.y + collisionObject->localScale.y >= other->localPosition.y);/* &&
                            (collisionObject->localPosition.y + collisionObject->localScale.y <= other->localPosition.y + other->localScale.y);*/
        
        collision->plus_x = (collisionObject->localPosition.x + collisionObject->localScale.x >= other->localPosition.x);/* &&
                            (collisionObject->localPosition.x + collisionObject->localScale.x <= other->localPosition.x + other->localScale.x);*/
        
        return *collision;
    }
    
    bool Collision::detect_collision(Object* other)
    {
        CollisionVector collision = detect_nrm_collision(other);
        
        bool left_right = collision.plus_x && collision.minus_x;
        bool top_down   = collision.plus_y && collision.minus_y;
        
        return (left_right && top_down);
    }
    
    // Intersecção;
    CollisionIntersection::CollisionIntersection(Collision* collision)
    {
        this->collision = collision;
    }
    
    void CollisionIntersection::getIntersection(Object* other)
    {
        CollisionNormal collision_normal = collision->detect_fac_collision(other);
        CollisionVector collision_vector = collision->detect_nrm_collision(other);
        
        // Verificação de Colisão;
        if (collision->detect_collision(other))
        {
            // Intersecção do Eixo X;
            xIntersection.x = collision->collisionObject->localPosition.x < other->localPosition.x ? other->localPosition.x : other->localPosition.x + collision->collisionObject->localPosition.x;
            
            xIntersection.y = (collision->collisionObject->localPosition.x + collision->collisionObject->localScale.x) < other->localPosition.x + other->localScale.x ? (collision->collisionObject->localPosition.x + collision->collisionObject->localScale.x) - other->localPosition.x : other->localPosition.x + other->localScale.x;
            
            xIntersection.z = xIntersection.y - xIntersection.x;
            
            // Intersecção do Eixo Y;
            yIntersection.x = collision->collisionObject->localPosition.y + collision->collisionObject->localScale.y < other->localPosition.y + other->localScale.y ? collision->collisionObject->localPosition.y + collision->collisionObject->localScale.y : other->localPosition.y + other->localScale.y;
            
            yIntersection.y = collision->collisionObject->localPosition.y < other->localPosition.y ? other->localPosition.y : collision->collisionObject->localPosition.y;
            
            yIntersection.z = yIntersection.y - yIntersection.x;
            
        } else
        {
            xIntersection = vec3(0.0f, 0.0f, 0.0f);
            yIntersection = vec3(0.0f, 0.0f, 0.0f);
        }
        
        // Desenho da Intersecção;
        if (RectangleDraw)
        {
            Rectangle->rectVisible = collision->detect_collision(other);
            
            if (Rectangle->rectVisible)
            {
                // Tenenses de Intersecção;
                if (RectangleDraw)
                {
                    for (int index = 0; index < 4; index++)
                        Rectangle->Vertex.VertexColor[index] = vec4(1.0f, 1.0f, 1.0f, 1.0f) - collision->collisionObject->Rectangle.Vertex.VertexColor[index];
                    
                    Rectangle->Vertex.VertexPosition[0] = vec2(xIntersection.x, yIntersection.x);
                    Rectangle->Vertex.VertexPosition[1] = vec2(xIntersection.y, yIntersection.x);
                    Rectangle->Vertex.VertexPosition[2] = vec2(xIntersection.y, yIntersection.y);
                    Rectangle->Vertex.VertexPosition[3] = vec2(xIntersection.x, yIntersection.y);
                }
            }
        }
    }
    
    void CollisionIntersection::drawIntersection(Scene& scene)
    {
        Rectangle = new Rect();
        RectangleDraw=true;
        scene.addToRender(Rectangle);
    }
} }








