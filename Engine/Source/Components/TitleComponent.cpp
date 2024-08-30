#include "TitleComponent.h"
#include "..//FrameWork/Scene.h"
#include "..//FrameWork/Actor.h"

FACTORY_REGISTER(TitlemapComponent)

void TitlemapComponent::Read(const json_t& value)
{

	Json::Read(value, "numColumns", numColumns);
	Json::Read(value, "numRows", numRows);
	Json::Read(value, "titleSize", titleSize);
	Json::Read(value, "titleNames", titleNames);
	Json::Read(value, "titles", titles);

	TitlemapComponent::Initialize();
}

void TitlemapComponent::Write(json_t& value)
{
}

void TitlemapComponent::Initialize()
{
	for (int i = 0; i < titles.size(); i++) {

		int titleindez = titles[i];

		if (titleindez == 0) continue;
	
		std::string titleName = titleNames[titleindez];

		auto title = Factory::Instance().Create<Actor>(titleName);

		if (title) {
			//No Offset
			int x = i % numColumns;
			int y = i / numColumns;

			title->transfrom.position = owner->transfrom.position + Vector2{ x, y } *titleSize;
			owner->scene->AddActor(std::move(title), true);
		}
	}
}

void TitlemapComponent::Update(float dt)
{
}