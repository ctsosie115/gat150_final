#include "..//..//Engine/Source/Engine.h"
#include "..//Source/my_game.h"
#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());

	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	
	////Json
	//// !! this code is not neccessary, it just shows the contents of the file !!
	//std::string fileName = "C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/gat150_cdtsosie/Resource Files/titlemap.json";
    //std::string fileName = "C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/scenes/json.txt";
	//std::string buffer; 
	//File::ReadFile(fileName, buffer);

	////// show the contents of the json file
	//std::cout << buffer << std::endl;

	////// create json document from the json file contents
	//rapidjson::Document document;
	//Json::Load(fileName, document);

	//std::string name;
	//int age = 0;
	//float speed = 0.0;
	//bool isAwake = false;
	//Vector2 position{};
	//Color color{};
	//
	//READ_DATA(document, name);
	//READ_DATA(document, age); 
	//READ_DATA(document, speed); 
	//READ_DATA(document, isAwake);
	//READ_DATA(document, position); 
	//READ_DATA(document, color); 

	//////// show the data
	//std::cout << name << std::endl;
	//std::cout << age << std::endl;
	//std::cout << speed << std::endl;
	//std::cout << isAwake << std::endl;
	//std::cout << "position.x = " << position.x << " and position.y = " << position.y << std::endl;
	//std::cout << "color{r,g,b,a} = { " << color.r << " , " << color.g << " , " << color.b << ", " << color.a << " }" << std::endl;

	Engine* m_engine = new Engine();
	m_engine->Initialize();
	MyGame myGame(m_engine);

	//// create texture, using shared_ptr so texture can be shared 
	Renderer getRenderer = m_engine->GetRenderer();

	//std::unique_ptr<Scene> scence = std::make_unique<Scene>(m_engine.get());
	//I changed file structure so I have to get the paths for textures, audio, scene, and fonts agian
	//engine->GetAudio().PlaySound("C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/sounds/dragon_background_music.wav"); 
	//
	//res_t<Texture> texture = ResourceManger::Instance().Get<Texture>("C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/textures/fish_man.png", *m_engine->renderer); 
	//texture->Load("C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/textures/fish_man.png", *m_engine->renderer);

	//res_t<Font> font = ResourceManger::Instance().Get<Font>("C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/fonts/ArcadeClassic.ttf", 12);

	//std::unique_ptr<Text> text = std::make_unique<Text>(font);
	//text->Create(getRenderer, "text", { 255,255,255,255 });

	//std::unique_ptr<TextComponent> textcomponent = std::make_unique<TextComponent>();
	//textcomponent->Initialize();

	//std::unique_ptr<Audio> audio = std::make_unique<Audio>();

//"C: / Users / ctsosie / Neumont / Year 1 Neumont / Q 3 / Sprint 1 / C++ / C++ Visual Studio / GAT150 GameEngine / gat150_cdtsosie / Build / Assets / textures/background.png"

	//m_engine->audio->PlaySound("C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/sounds/dragon_background_music.wav");

	while (!m_engine->IsQuit())
	{
		//Update
		m_engine->Update();
		myGame.Update(m_engine->GetTime().GetDeltaTime(), m_engine->GetTime().GetTime());

		m_engine->GetRenderer().BeginFrame();
		myGame.Draw(*(m_engine->renderer));
		m_engine->GetRenderer().EndFrame();
	}

	ResourceManger::Instance().Clear();

	myGame.Shutdown();
	m_engine->Shutdown();

	return 0;
}