#pragma once
#include "../Components/TextureComponent.h"
#include "../Renderer/Texture.h"
#include <map>

class TextureAnimationComponent : public TextureComponent
{
public:
	struct Animation
	{
		std::string name;

		float fps = 0;
		bool loop = true;

		int numColumns = 0;
		int numRows = 0;
		int startFrame = 0;
		int endFrame = 0;

		std::string textureName;
		std::shared_ptr<Texture> texture;
	};

public:
	static const char* GetTypeName() {
		return "TextureAnimationComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<TextureAnimationComponent>(*this);
	}

	void Initialize() override;
	void Update(float dt) override;
	void SetAnimation(const std::string& name, bool update = true);

private:
	void UpdateSource();

public:
	int frame = 0;
	float frameTimer = 0;
	std::string animationName;

private:
	std::map<std::string, Animation> animations;
	Animation* animation = nullptr;
};