#pragma once
#include "../Texture.h"
#include "../Renderer/Render.h"
#include "../Renderer/Text.h"
#include "../Components/RenderComponent.h"


class TextComponent : public RenderComponent
{
public:
	TextComponent() = default;
	TextComponent(const TextComponent& other);

	static const char* GetTypeName() {
		return "TextComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<TextComponent>(*this);
	}

	void Initialize();
	void Update(float dt);
	void SetText(const std::string text);
	void SetFontName(const std::string& fontNames) { fontName = fontNames; }
	void SetSize(int size) { fontsize = size; }
	void SetColor(const Color& colors) { color = colors; }

	// Inherited via RenderComponent
	void Draw(Renderer& renderer) override;
	void Draw(Renderer& renderer, Transform& transform, res_t<Texture>& texture);

public:
	std::string textStr;
	std::string fontName;
	int fontsize;
	Color color = {255.0f,255.0f,255.0f,255.0f};
	Vector2 position = { 100.0f,100.0f };
	bool textchanged;
	bool hflip{ false };

	std::unique_ptr<class Text> texts; 
	std::string textureName;
	res_t<Texture> texture;

};
