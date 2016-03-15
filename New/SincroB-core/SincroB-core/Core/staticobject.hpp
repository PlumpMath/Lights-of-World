#include "scene.hpp"
#include "object.hpp"

namespace engine { using namespace maths; namespace graphics {
    
    class StaticObject: public Object
    {
    public:
        StaticObject(const char* name, Scene& scene, int draw_layer=0);
        ~StaticObject();
        
        void applyMovement(vec2 movement);
        void setVisible(bool visible);
    };
    
} }
