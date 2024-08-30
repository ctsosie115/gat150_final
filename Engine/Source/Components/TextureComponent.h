#pragma once
#include "RenderComponent.h"
#include "../Texture.h"


class TextureComponent : public RenderComponent
{
public:
	static const char* GetTypeName() {
		return "TextureComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
		virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<TextureComponent>(*this);
	}

	// Inherited via Component;
	void Initialize() override;

	void Update(float dt) override;

	void Draw(Renderer& renderer) override;

	void setTexture(const res_t<Texture>& texture);

	void SetText(const std::string& text);

public:
	//std::unique_ptr<class
	bool hflip =false;
	std::string textureName;
	res_t<Texture> texture;
	Rect source;
	int scale = 1;
};