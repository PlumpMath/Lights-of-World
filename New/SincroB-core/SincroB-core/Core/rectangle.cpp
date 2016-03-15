#include "rectangle.hpp"

namespace engine { using namespace maths; namespace graphics {

    void Rect::setColor(vec4 color)
    {
        for (int vert_idx = 0; vert_idx < 4; vert_idx++)
            Vertex.VertexColor[vert_idx] = color;
    }
    
    void Rect::loadTexture(const char* texture_path)
    {
        Texture.TextureContext.loadImageTexture(texture_path);
        
        // Contextos da imagem;
        Texture.TexturePath = texture_path;
        Texture.TextureID = Texture.TextureContext.TextureID;
        Texture.width = Texture.TextureContext.TextureWidth;
        Texture.height = Texture.TextureContext.TextureHeight;
    }
    
    void Rect::freeTexture()
    {
        glDeleteTextures(1, &Texture.TextureID);
    }
    
    void Rect::update()
    {
        if (Texture.TextureAlpha)
        {
            glEnable(GL_BLEND);
            glEnable(GL_ALPHA);
            
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }
        
        if (Texture.TexturePath && Texture.TextureID)
            glEnable(GL_TEXTURE_2D);
        
        draw();
        
        if (Texture.TexturePath && Texture.TextureID)
            glDisable(GL_TEXTURE_2D);
    }
    
    void Rect::draw() const
    {
        if (rectVisible)
        {
            if (Texture.TexturePath && Texture.TextureID)
                Texture.TextureContext.loadTexture(&Texture.TextureID);
            
            // Desenho;
              glBegin(GL_QUADS);
            for (int vert_idx = 0; vert_idx < 4; vert_idx++)
            {
                // Verifica se existe um path de textura;
                if (Texture.TexturePath && Texture.TextureID)
                    glTexCoord2f(Texture.TextureCoords[vert_idx].x, Texture.TextureCoords[vert_idx].y);
                
                float vertex_x = (Vertex.VertexPosition[vert_idx].x * localScale.x) + localPosition.x;
                float vertex_y = (Vertex.VertexPosition[vert_idx].y * localScale.y) + localPosition.y;
                vec4 vertex_color = Vertex.VertexColor[vert_idx];
                
                // Vertex position;
                glColor4f(vertex_color.x, vertex_color.y, vertex_color.z, vertex_color.w);
                glVertex2f(vertex_x, vertex_y);
            } glEnd();
        }
    }
    
    void Rect::init()
    {
        // Bind de Vertices;
        glGenVertexArrays(1, &this->vbo);
        glBindVertexArray(this->vbo);
        
        // Textura;
        Texture.width = 0;
        Texture.height = 0;
        
        Texture.TextureID = NULL;
        Texture.TexturePath = NULL;
        
        // Coordenada de Texturas;
        Texture.TextureCoords[0] = vec2( 1.0f,  1.0f);
        Texture.TextureCoords[1] = vec2( 0.0f,  1.0f);
        Texture.TextureCoords[2] = vec2( 0.0f,  0.0f);
        Texture.TextureCoords[3] = vec2( 1.0f,  0.0f);
        
        // Coordenadas Iniciais de Vertices;
        Vertex.VertexPosition[0] = vec2( 1.0f,  1.0f);
        Vertex.VertexPosition[1] = vec2( 0.0f,  1.0f);
        Vertex.VertexPosition[2] = vec2( 0.0f,  0.0f);
        Vertex.VertexPosition[3] = vec2( 1.0f,  0.0f);
        
        // Posição e Scala local;
        localPosition = vec2(0.0f, 0.0f);
        localScale = vec2(1.0f, 1.0f);
        
        worldPosition = vec2(0.0f, 0.0f);
        worldScale = vec2(1.0f, 1.0f);
        
        // Pinturas Iniciais de Vertices;
        setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
        rectVisible = true;
    }
    
    void Rect::destroy()
    {
        // Limpa de arrays;
        glDeleteVertexArrays(1, &vbo);
    }
} }