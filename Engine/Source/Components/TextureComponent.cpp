#include "TextureComponent.h"
#include "../Renderer/Render.h"
#include "../FrameWork/Actor.h"
#include "../Resources/ResourceManger.h"
#include "..//FrameWork/Scene.h"

void TextureComponent::Initialize()
{
	if (!textureName.empty()) {

		//t_texture = ResourceManger::Instance().Get<Texture>(textureName,t_texture);
		//t_texture = ResourceManger::Instance().Get<Texture>(textureName, owner->m_scene->engine->GetRenderer());
		texture = ResourceManger::Instance().Get<Texture>(textureName, owner->scene->engine->GetRenderer());
	
		if (!texture) {
			// Handle error, maybe load a default texture
			std::cerr << "Failed to load texture: " << textureName << std::endl;
			texture = res_t<Texture>();
			return;
		}

		if (texture && source.w == 0 && source.h == 0)
		{
			source.x = 0;
			source.y = 0;
			// set source from texture width and height
			source.w = (int)texture->GetSize().x;
			source.h = (int)texture->GetSize().y;
		}
		
	}
}

void TextureComponent::Update(float dt)
{
	//
}

void TextureComponent::Draw(Renderer& renderer)
{
	//The trnasform is public access
	Transform transform = owner->transfrom;

	//renderer.DrawTexture(t_texture.get(), transform, source, hflip);

	renderer.DrawTexture(texture, transform, source);
}

void TextureComponent::setTexture(const res_t<Texture>& textured)
{
	texture = textured;
}


void TextureComponent::SetText(const std::string& text)
{

}

void TextureComponent::Read(const json_t& value)
{
	TextureComponent::Initialize();
	
	READ_DATA(value, textureName);
	READ_DATA(value, source);
	READ_DATA(value, hflip);
	READ_DATA(value, scale);
}

void TextureComponent::Write(json_t& value)
{
}

