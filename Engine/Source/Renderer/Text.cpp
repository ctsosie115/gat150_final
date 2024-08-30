#include "Text.h"
#include <cassert>
#include <iostream>

Text::~Text()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
}

bool Text::Create(Renderer& renderer, const std::string& text, const Color& color)
{
	// create a surface using the font, text string and color
	SDL_Color c{ Color::Toint(color.r), Color::Toint(color.g), Color::Toint(color.b), Color::Toint(color.a) };
	//SDL_Surface* surface = TTF_RenderText_Solid(m_font->GetTTFFont(), text.c_str(), c);
	SDL_Surface* surface = TTF_RenderText_Solid(fonts.get()->GetTTFFont(), text.c_str(), c);

	if (surface == nullptr)
	{
		std::cerr << "Could not create surface.\n";
		return false;
	}

	// create a texture from the surface, only textures can render to the renderer
	texture = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface);
	if (surface == nullptr)
	{
		SDL_FreeSurface(surface);
		std::cerr << "Could not create texture" << SDL_GetError() << std::endl;
		return false;
	}


	// free the surface, no longer needed after creating the texture
	SDL_FreeSurface(surface);

	return true;
}

void Text::Draw(Renderer& renderer, int x, int y)
{
	assert(texture);

	// query the texture for the texture width and height
	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	// copy the texture onto the renderer
	SDL_Rect rect{ x, y, width, height };
	SDL_RenderCopy(renderer.GetRenderer(), texture, NULL, &rect);
}