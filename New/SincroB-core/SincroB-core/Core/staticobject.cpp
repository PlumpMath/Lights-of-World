#include "staticobject.hpp"
#include "rectangle.hpp"

namespace engine { using namespace maths; namespace graphics {
    
    StaticObject::StaticObject(const char* name, Scene& scene, int draw_layer)
    {
        this->name = name;
        scene.addToRender(this, draw_layer);
    }
    
    StaticObject::~StaticObject()
    {
        
    }
    
    void StaticObject::applyMovement(vec2 movement)
    {
        this->localPosition += movement;
    }
    
    void StaticObject::setVisible(bool visible)
    {
        
    }
    
} }