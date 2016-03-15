#include "Core/sincrob.hpp"
#include "collisions.hpp"

#include <vector>

int main(int argc, const char **argv)
{
    using namespace engine;
    using namespace graphics;
    using namespace maths;
    
    // Inicialização;
    Window newWindow;
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    
    // Cena principal;
    Scene newScene("Scene");
    
    StaticObject *box = new StaticObject("box", newScene);
    //StaticObject *box2 = new StaticObject("box2", newScene);
    StaticObject* objects[4];
    
    objects[0] = new StaticObject("box0", newScene, 0);
    objects[1] = new StaticObject("box1", newScene, 0);
    objects[2] = new StaticObject("box2", newScene, 0);
    objects[3] = new StaticObject("box3", newScene, 0);
    
    for (int i = 0; i < 4; i++)
    {
        objects[i]->localScale /= vec2(5.0f, 5.0f);
        objects[i]->localPosition.x += 0.3 * i;
        objects[i]->localPosition.x -= 0.9;
    }
    box->localScale /= vec2(7.0f, 7.0f);
    box->setColor(vec4(1.0f, 0.0f, 1.0f, 1.0f));
    box->localPosition.x = -0.5f;
    
    Collision* collision = new Collision(box);
    CollisionIntersection* collision_intersection = new CollisionIntersection(collision);
    collision_intersection->drawIntersection(newScene);
    StaticObject* collision_object = objects[0];
    
    float velocityy;
    float velocityx;
    vec2 velocity;
    
    while (newWindow.closedWindow())
    {
        newWindow.clearWindow();
        
        velocityx = ((int) (newWindow.isKeyPressed(RIGHTARROWKEY)) - (int) (newWindow.isKeyPressed(LEFTARROWKEY))) * 0.01;
        velocityy = ((int) (newWindow.isKeyPressed(UPARROWKEY   )) - (int) (newWindow.isKeyPressed(DOWNARROWKEY))) * 0.01;

        for (int i = 0; i < 4; i++)
        {
            if (collision_intersection->collision->detect_collision(objects[i]))
            {
                collision_object = objects[i];
                break;
                
            }
        } collision_intersection->getIntersection(collision_object);
        std::cout << collision_object->localPosition << std::endl;
        
        velocity.x = velocityx;
        velocity.y = velocityy;
    
        box->applyMovement(velocity);
        
        newScene.update();
        newWindow.updateWindow();
    }

    return 0;
}