#include "my_game.h"
#include "..//..//Engine/Source/Engine.h"
#include <memory>

MyGame::MyGame(Engine* engine)
{
    m_engine = engine;
    MyGame::Initialize();
}

bool MyGame::Initialize()
{
    m_scene = new Scene(m_engine);
    m_scene->Initialize();

    //m_scene = std::make_unique<Scene>(m_engine);
    std::string scenceNames[] = { "C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/gat150_cdtsosie/Resource Files/titlemap.json" };

    rapidjson::Document document;
    for (auto scenceName : scenceNames) {
        Json::Load(scenceName, document);
        if (document.IsObject()) {
            m_scene->Read(document);  // Initialize the scene with JSON data
        }
        else {
            std::cerr << "Error: JSON document is not an object or failed to load." << std::endl;
            return false;
        }
    }

    /*ADD_OBSERVER(PlayerDead, SpaceGame::OnPlayerDead);
    ADD_OBSERVER(AddPoints, SpaceGame::ONADDPOINTS);*/

    m_font = new Font();
    //m_font->Load("C:/Users/ctsosie/Neumont/Year 1 Neumont/Q 3/Sprint 1/C++/C++ Visual Studio/GAT150 GameEngine/gat150_cdtsosie/Build/Assets/fonts/ArcadeClassic.ttf", 20);

    m_fontLarge = new Font();

    return true;
}

void MyGame::Shutdown()
{
    m_scene->RemoveAll();
    m_engine->Shutdown();
}

void MyGame::Update(float dt, float time)
{
    m_scene->Update(dt);

    switch (m_state)
    {
    case eState::Title:


        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
        {
            m_state = eState::StartGame;
        }

        m_spawnTimer = m_spawnTime;

        break;
    case eState::StartGame:
        m_score = m_scene->GetScore();
        m_lives = 3;

        m_engine->GetTime().Reset();
        m_state = eState::StartLevel;
        break;
    case eState::StartLevel:
        m_scene->RemoveAll();
        {

        }

        m_spawnTime = 3;
        m_spawnTimer = m_spawnTime;

        m_state = eState::Game;
        break;
    case eState::Game:
        m_spawnTimer -= dt * (time * 0.1);
        m_pickupTimer -= dt * (time * 0.1);
        m_pickup2Timer -= dt * (time * 0.1);

        if (m_spawnTimer <= 0)
        {
            m_spawnTimer = 3;

            // create enemy

        }
        if (m_pickupTimer <= 0) {
            //create pickup

            //if ((m_scene->GetActor<Pickup>() == nullptr)) {

            //}
              
        }

        //if player dies
            //OnPlayerDeath();
        
        break;
    case eState::PlayerDead:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
            m_state = eState::StartLevel;
        }
        break;
    case eState::GameOver:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
            m_state = eState::Title;
        }
        break;
    default:
        break;
    }

    m_scene->Update(dt);
}

void MyGame::Draw(Renderer& renderer)
{
    switch (m_state)
    {
    case MyGame::eState::Title:

        break;

    case MyGame::eState::GameOver:

        break;

    default:
        break;
    }
    m_scene->Draw(renderer);
}

void MyGame::OnPlayerDeath()
{
    m_lives--;
    m_state = (m_lives == 0) ? eState::GameOver : eState::PlayerDead;
    m_stateTimer = 3;
}
