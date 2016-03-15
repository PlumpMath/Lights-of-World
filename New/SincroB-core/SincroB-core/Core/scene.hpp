#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <string>
#include <vector>
#include <iostream>

namespace engine { namespace graphics {
#define RENDER_LAYERS 6
    
    struct Object;
    struct Rect;
    
    struct Scene
    {
        Scene(std::string name) { this->name = name; };
        ~Scene() {};
        
        std::string name;
        
        // Quantidade de itens;
        int lenght_objects=0;
        int lenght_process;
        
        struct Contents
        {
            std::vector<Object*> objects[RENDER_LAYERS];
            std::vector<Rect*> rectangles[RENDER_LAYERS];

        } contents;

        void update();
        void render();
        
        void addToRender(Object* object, int draw_layer=0);
        void addToRender(Rect* rectangle, int draw_layer=0);
        
        friend std::ostream& operator << (std::ostream& stream, const Scene& scene);
    };
    
} }

#endif // __SCENE_HPP__