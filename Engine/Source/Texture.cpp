#include "Texture.h"
#include "..//Source/Renderer/Render.h"
#include <SDL_surface.h>
#include <SDL_image.h>
#include <iostream>
#include "Core/Ensert.h"

Texture::~Texture()
{
    // if texture exists, destroy texture
    if (textures != NULL) SDL_DestroyTexture(textures);
}


bool Texture::Load(const std::string& filename, Renderer& renderer)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());

    if (surface == nullptr)
    {
        std::cerr << "Could not load image: " << filename << std::endl;
        return false;
    }

    textures = SDL_CreateTextureFromSurface(renderer.renderer, surface);

    // once texture is created, surface can be freed up
    if (textures == nullptr) 
    {
        std::cerr << "Could not create texture: " << filename << std::endl;
        return false;
    }
    // Set size(assuming the surface size is the texture size)
    size_.x = static_cast<float>(surface->w);
    size_.y = static_cast<float>(surface->h);

    SDL_FreeSurface(surface);
    return true;
}

Vector2 Texture::GetSize()
{
    
    if (textures == nullptr)  // Debugging step
    {
        std::cerr << "m_texture is null!" << std::endl;
        return Vector2{ 30, 30 };
    }

    //ASSERT(m_texture != nullptr);

    SDL_Point size{};

    //SDL_QueryTexture(m_texture, NULL, NULL, ...pass address of size.x and size.y.);
    SDL_QueryTexture(textures, NULL, NULL, &size.x, &size.y);

    //return ...Vector2 with size.x and size.y.;
    return Vector2{ size.x, size.y };
}

bool Texture::Create(std::string name, ...)
{
	va_list args; //arugments from the item inside the ...
	va_start(args, name);

	Renderer render = va_arg(args, Renderer);

	va_end(args);

    return Load(name, render);
}


