#include "TextComponents.h"
#include "..//FrameWork/Actor.h"
#include "..//..//Source/Resources/ResourceManger.h"
#include "../Renderer/Transform.h"
#include "..//FrameWork/Scene.h"
#include <iostream>

TextComponent::TextComponent(const TextComponent& other)
{
	textStr = other.textStr;
	fontName = other.fontName;
	fontsize = other.fontsize;
	color = other.color;

	textchanged = true;

	//Copy m_text
	if (other.texts) {
		texts = std::make_unique<Text>(*other.texts.get());
	}
}

void TextComponent::Read(const json_t& value)
{
	READ_DATA(value, textureName);
	READ_DATA(value, hflip);
	//READ_DATA(value, source);

	READ_DATA(value, textStr);
	READ_DATA(value, fontName);
	READ_DATA(value, fontName);
	READ_DATA(value, color);
}

void TextComponent::Write(json_t& value)
{
}

void TextComponent::Draw(Renderer& renderer)
{
	// The trnasform is public access
	Transform transform = owner->GetTransform();
	renderer.DrawTexture(texture.get(), transform.position.x, transform.position.y, transform.rotation);

}
void TextComponent::Draw(Renderer& renderer, Transform& transform, res_t<Texture>& texture)
{
	// update text if text has changed
	if (textchanged)
	{
		textchanged = false;
		texts->Create(renderer, textStr, color);
	}

	renderer.DrawTexture(texture, owner->transfrom);

}

void TextComponent::Initialize()
{
	if (!textureName.empty()) {
		res_t<Font> font = ResourceManger::Instance().Get<Font>(fontName, fontsize);
		texts = std::make_unique<Text>(font);
	}
}

void TextComponent::Update(float dt)
{
	//
}

void TextComponent::SetText(const std::string text)
{
	if(textStr != text){
		textStr = text;
		textchanged = true;
	}
}

//add read and write
//read
//Read_Data Required (value, transform)
