#pragma once
#include "../Source/Resources/Resources.h"
#include "Renderer/Render.h"
#include "Renderer/Vector2.h"
#include <string>
#include <SDL.h>

class Renderer;

class Texture : public Resource
{
public:
	Texture() = default;
	~Texture();

	bool Load(const std::string& filename, class Renderer& renderer);
	bool Create(std::string name, ...) override;
	SDL_Texture* GetSDLTexture() { return textures; }

	Vector2 GetSize();

	friend class Renderer;

private:
	struct SDL_Texture* textures{ nullptr };
	Vector2 size_;
};