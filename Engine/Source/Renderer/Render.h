#pragma once
#include "../Texture.h"
#include "..//Renderer/Transform.h"

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <Texture.h>

class Renderer
{
public:
	Renderer() = default;

	bool Iitialize();
	void Shutdown();
	bool CreateWindow(std::string title, int width, int height);
	void BeginFrame();
	void EndFrame();

	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawLine(float x1, float y1, float x2, float y2);
	void DrawPoint(int x1, int y1);
	void DrawPoint(float x1, float y1);
	void DrawRect(int x, int y, int w, int h);
	void DrawRect(float x, float y, float  w, float h);

	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

	SDL_Renderer* GetRenderer() { return renderer; }

	friend class Texture;
	friend class Text;

	void DrawTexture(Texture* texture, float x, float y, float angle = 0.0f);
	void DrawTexture(std::weak_ptr<class Texture> texture, const struct Transform& transform, bool hflip = false);
	void DrawTexture(std::weak_ptr<class Texture> texture, const struct Transform& transform, const Rect& srcRect, bool hflip = false);

	void DrawTexture(Texture* texture, Transform& transform);
	void DrawTexture(const res_t<Texture>& texture, float x, float y, float scale);


	private:
	SDL_Window* window{ nullptr };
	SDL_Renderer* renderer{ nullptr };

	int width = 0;
	int height = 0;
};