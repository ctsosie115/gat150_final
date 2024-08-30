#include "..//../Source/Engine.h"

//#include <crtdbg.h>

bool Engine::Initialize()
{
    //Enable Memory Check
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    renderer = std::make_unique<Renderer>();
    input = std::make_unique<Input>();
    audio = std::make_unique<Audio>();
    particlesystem = std::make_unique<ParticleSystem>();
    time = std::make_unique<Time>();

    physics = std::make_unique<Physics>();
    audioSource = std::make_unique<AudioSource>();
    audioClip = std::make_unique<AudioClip>();
    audioComponent = std::make_unique<AudioComponent>();

    renderer->Iitialize();
    input->Initialize();
    audio->Initialize();
    physics->Initialize();
    
    renderer->CreateWindow("Game Engine", 1000, 800);
    
    return true;
}

void Engine::Shutdown() const
{
    renderer->Shutdown();
    input->Shutdown();
    audio->Shutdown();
    physics->Shutdown();

    //Display Memory Leaks
    _CrtMemDumpAllObjectsSince(NULL);
}


void Engine::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        {
            quit = true;
        }
    }

    time.get()->Tick();
    input->Update();
    audio->Update();
    particlesystem->Update(time->GetDeltaTime());
    physics->Update(time->GetDeltaTime());
}
