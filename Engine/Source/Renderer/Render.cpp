#pragma once

#include "..//../Source/Renderer/Render.h"
#include <iostream>
#include "../Texture.h"

bool Renderer::Iitialize()
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return false;
	}
	// initialize TTF SDL
	if (TTF_Init() < 0)
	{
		std::cerr << "Error initializing SDL TTF: " << SDL_GetError() << std::endl;
		return false;
	}
	// initialize Image SDL, supports BMP, JPG, and PNG
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
	{
		std::cerr << "Error initializing SDL Image: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
void Renderer::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_Quit();

	IMG_Quit();
}

bool Renderer::CreateWindow(std::string title, int width, int height)
{
	width = width;
	height = height;
	// create window
		// returns pointer to window if successful or nullptr if failed
	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cerr << "Error creating Rendereer: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	return true;
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Renderer::BeginFrame()
{
	SDL_RenderClear(renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(renderer);
}

void Renderer::DrawLine(int x1, int y1, int x2, int y2)

{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
}

void Renderer::DrawPoint(int x1, int y1)
{
	SDL_RenderDrawPoint(renderer, x1, y1);
}

void Renderer::DrawPoint(float x1, float y1)

{
	SDL_RenderDrawPointF(renderer, x1, y1);
}

void Renderer::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect rect{ x - w / 2, y - h / 2,w,h };
	SDL_RenderFillRect(renderer, &rect);
}

void Renderer::DrawRect(float x, float y, float w, float h)
{
	SDL_FRect rect{ x - w / 2,y - h / 2,w,h };
	SDL_RenderFillRectF(renderer, &rect);
}

void Renderer::DrawTexture(Texture* texture, float x, float y, float angle)
{

	if (texture != nullptr && texture->GetSDLTexture() != nullptr) {
		Vector2 size = texture->GetSize();
		SDL_FRect destRect{};
		destRect.x = x - size.x * 0.5f;
		destRect.y = y - size.y * 0.5f;
		destRect.w = texture->GetSize().x;
		destRect.h = texture->GetSize().y;

		SDL_RenderCopyExF(renderer, texture->GetSDLTexture(), NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
	}
}

void Renderer::DrawTexture(std::weak_ptr<class Texture> texture, const Transform& transform, bool hflip)
{
	Vector2 size = texture.lock()->GetSize();

	SDL_FRect destRect{};
	destRect.x = transform.position.x - size.x * 0.5f;
	destRect.y = transform.position.y - size.y * 0.5f;
	destRect.w = size.x;
	destRect.h = size.y;

	SDL_RenderCopyExF(renderer, texture.lock()->GetSDLTexture(), NULL, &destRect, transform.rotation, NULL, (hflip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Renderer::DrawTexture(std::weak_ptr<class Texture> texture, const Transform& transform, const Rect& srcRect, bool hflip)
{
	Vector2 size = Vector2{ srcRect.w, srcRect.h } * 2;
	//
	//

	SDL_FRect destRect{};
	destRect.x = srcRect.x - size.x;
	destRect.y = srcRect.y - size.y;
	destRect.w = size.x;
	destRect.h = size.y;

	
	SDL_RenderCopyExF(renderer, texture.lock()->textures, (SDL_Rect*)&srcRect, &destRect, transform.rotation, NULL, (hflip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Renderer::DrawTexture(Texture* texture, Transform& transform)
{
	Vector2 size = texture->GetSize() * transform.scale; 

	SDL_FRect destRect{};
	destRect.x = transform.position.x - size.x * 0.5f;
	destRect.y = transform.position.y - size.y * 0.5f;
	destRect.w = size.x;
	destRect.h = size.y;

	SDL_RenderCopyExF(renderer, texture->GetSDLTexture(), NULL, &destRect, transform.rotation, NULL, SDL_FLIP_NONE);
}

void Renderer::DrawTexture(const res_t<Texture>& texture, float x, float y, float scale)
{
	Vector2 size = texture->GetSize(); 

	SDL_FRect destRect{}; 
	destRect.x = x - size.x * 0.5f; 
	destRect.y = y - size.y * 0.5f; 
	destRect.w = texture->GetSize().x; 
	destRect.h = texture->GetSize().y; 

	SDL_RenderCopyExF(renderer, texture->GetSDLTexture(), NULL, &destRect, scale, NULL, SDL_FLIP_NONE);
}
