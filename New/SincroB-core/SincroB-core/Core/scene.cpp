#include "scene.hpp"
#include "objects.hpp"

namespace engine { namespace graphics {
    
    void Scene::update()
    {
        this->render();
    }

    void Scene::render()
    {
        int counter_objs=0;
        for (int layer = 0; layer < RENDER_LAYERS; layer++)
        {
            for (int index = 0; index < this->contents.objects[layer].size(); index++)
            {
                this->contents.objects[layer][index]->update();
            } counter_objs += this->contents.objects[layer].size();
            
            for (int index = 0; index < this->contents.rectangles[layer].size(); index++)
            {
                this->contents.rectangles[layer][index]->update();
            } // Desenhos de simples retangulos não associados a objetos;
            
        } lenght_objects = counter_objs;
    }
    
    void Scene::addToRender(Object* object, int draw_layer)
    {
        if (draw_layer > RENDER_LAYERS - 1)
            draw_layer = RENDER_LAYERS - 1;
        
        if (draw_layer < 0)
            draw_layer = 0;
        
        this->contents.objects[draw_layer].push_back(object);
    }
    
    void Scene::addToRender(Rect* rectangle, int draw_layer)
    {
        if (draw_layer > RENDER_LAYERS - 1)
            draw_layer = RENDER_LAYERS - 1;
        
        if (draw_layer < 0)
            draw_layer = 0;
        
        this->contents.rectangles[draw_layer].push_back(rectangle);
    }
    
    std::ostream& operator << (std::ostream& stream, const Scene& scene)
    {
        stream << "<Scene: <objects:" << scene.lenght_objects << "> <layers:" << RENDER_LAYERS << "> <name:" << scene.name << "> DynamicScene>";
        return stream;
    }
    
} }