#pragma once
#include "..//..//Source/Renderer/Font.h"
#include "..//..//Source/Renderer/Color.h"
#include "..//..//Source/Renderer/Render.h"

class Text
{
public:
	Text() = default;
	Text(Font* font) : font{ font } {}
	Text(const res_t<Font>& font) : fonts(font) {}
	~Text();

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, int x, int y);

	void SetFont(Font *font) { font = font; }
	Font* GetFont() { return font; };

private:
	Font* font{ nullptr };
	res_t<Font> fonts;
	SDL_Texture* texture{ nullptr };
};