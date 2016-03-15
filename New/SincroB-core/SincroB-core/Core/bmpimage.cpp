#include "bmpimage.hpp"

namespace engine { namespace texture {
    
    unsigned int loadBMPTexture_ARGB(const char* filename, int& width, int& height)
    {
        unsigned int Texture;
        unsigned char * Data;
        
        Data = loadBMPFile_ARGB(filename, width, height);
        
        if (Data)
        {
            glGenTextures(1, &Texture);
            glBindTexture(GL_TEXTURE_2D, Texture);
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);
        
            free(Data);
        
            return Texture;
        } return NULL; // Detecção de erros;
    }
    
    unsigned char* loadBMPFile_ARGB(const char* filename, int& width, int& height)
    {
        unsigned char * Data;
        unsigned char Header[54];
        
        FILE* file = fopen(filename, "rb");
        
        if (file == NULL)
        {
            std::cout << "Ouve um erro ao carregar imagem! Verifique a existencia do arquivo..." << std::endl;
            return NULL;
        }
        
        fread(Header, 1, 54, file);
        
        width = *(int *)& (Header[0x12]);
        height = *(int *)& (Header[0x16]);
        
        Data = (unsigned char *) malloc(width * height * 4);
        
        fread(Data, 16, 1, file );
        fread(Data, width * height * 4, 1, file);
        
        fclose( file );
        
        for(int i = 0; i < width * height ; ++i)
        {
            int index = i * 4;
            
            unsigned char A, R, G, B;
            
            B = Data[index    ];
            G = Data[index + 1];
            R = Data[index + 2];
            A = Data[index + 3];
            
            Data[index    ] = A;
            Data[index + 1] = R;
            Data[index + 2] = G;
            Data[index + 3] = B;
        }
        
        return Data;
    }
} }