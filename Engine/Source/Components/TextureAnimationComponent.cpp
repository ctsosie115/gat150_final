#include "TextureAnimationComponent.h"
#include "../Renderer/Render.h"
#include "Framework/Actor.h"
#include "../Resources/ResourceManger.h"
#include "Engine.h"
#include "TitleComponent.h"
#include <Texture.cpp>

class RegisterTextureAnimationComponent {
public: RegisterTextureAnimationComponent() {
	Factory::Instance().Register<TextureAnimationComponent>("TextureAnimationComponent");
}
}; static RegisterTextureAnimationComponent register_instance;

void TextureAnimationComponent::Initialize()
{
	TextureComponent::Initialize();
	// set textures for animations
	for (auto& animation : animations)
	{
		animation.second.texture = ResourceManger::Instance().Get<Texture>(animation.second.textureName, owner->scene->engine->GetRenderer());
	}
	// set default animation
	if (!animationName.empty()) SetAnimation(animationName, false);

	// update the source if not defined
	if (source.w == 0 && source.h == 0)
	{
		UpdateSource();
	}
}
void TextureAnimationComponent::Update(float dt)
{
	TextureComponent::Update(dt);

	// update timer
	frameTimer -= dt;
	if (frameTimer <= 0)
	{
		frameTimer = 1.0f / animation->fps;
		frame++;
		if (frame > animation->endFrame) frame = animation->startFrame;
	}

	UpdateSource();
}
void TextureAnimationComponent::SetAnimation(const std::string& name, bool update)
{
	// prevent setting animation again
	if (animation && IsEqualIgonreCase(animation->name, name)) return;

	// find animation in animations
	if (animations.find(name) != animations.end())
	{
		// set new animation
		animation = &animations[name];

		// set texture
		//if (m_animation->texture) texture = m_animation->texture; 

		// reset frame information
		frame = animation->startFrame;
		frameTimer = 1.0f / animation->fps;

		if (update) UpdateSource();
	}
}

void TextureAnimationComponent::UpdateSource()
{
	// calculate subimage size
	//Vector2 size = texture->GetSize() / Vector2{ m_animation->numColumns, m_animation->numRows };
	int column = (frame - 1) % animation->numColumns;
	int row = (frame - 1) / animation->numColumns;

	// set source rect from current column/row and subimage size
	//source.x = (int)(column * size.x);
	//source.y = (int)(row * size.y);
	//source.w = (int)(size.x);
	//source.h = (int)(size.y);
}
void TextureAnimationComponent::Read(const json_t& value)
{
	TextureComponent::Read(value);

	// read in animation sequences
	if (HAS_DATA(value, animations) && GET_DATA(value, animations).IsArray())
	{
		for (auto& animationValue : GET_DATA(value, animations).GetArray())
		{
			Animation animation;

			Json::Read(animationValue, "name", animation.name, false);
			Json::Read(animationValue, "fps", animation.fps, false);
			Json::Read(animationValue, "numColumns", animation.numColumns, false);
			Json::Read(animationValue, "numRows", animation.numRows, false);
			Json::Read(animationValue, "startFrame", animation.startFrame, false);
			Json::Read(animationValue, "endFrame", animation.endFrame, false);
			Json::Read(animationValue, "textureName", animation.textureName, false);

			// add animation to animations
			animations[animation.name] = animation;
		}
	}

	READ_DATA(value, animationName);
}
void TextureAnimationComponent::Write(json_t& value)
{
	//
}

//FACTORY_REGISTER(TextureAnimationComponent)