#include "object.hpp"

namespace engine { using namespace maths; namespace graphics {
    
    void Object::destroy()
    {
        Rectangle.destroy();
    }
    
    void Object::loadImage(const char *image, bool alpha)
    {
        Rectangle.Texture.TextureAlpha = alpha;
        Rectangle.loadTexture(image);
    }
    
    void Object::setColor(vec4 color)
    {
        Rectangle.setColor(color);
    }
    
    void Object::update()
    {
        Rectangle.localPosition = localPosition;
        Rectangle.localScale = localScale;
        
        Rectangle.update();
    }
} }