#pragma once

//Auido
#include "Audio/Audio.h"
#include "Audio/AudioClip.h"
#include "Audio/AudioSource.h"

//Input
#include "Input/Input.h"

//FrameWork
#include "FrameWork/Scene.h"
#include "FrameWork/Actor.h"
#include "FrameWork/Object.h"
#include "../Source/Core/Singleton.h"

//Math
#include "Math/MathUTIS.h"
#include "Math/Random.h"
#include "Math/Rect.h"

//Core
#include "Core/CTime.h"
#include "Core/EFile.h"
#include "Core/Ensert.h"
#include "Core/EString.h"
#include "Core/Json.h"
#include "Core/Factory.h"
#include "Core/Serializable.h"

//Renderer
#include "Renderer/Color.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Particle.h"
#include "Renderer/Particle_System.h"
#include "Renderer/Render.h"
#include "Renderer/Transform.h"
#include "Renderer/Vector2.h"
#include "..//Source/Texture.h"
#include "..//Source/Renderer/Text.h"

//Resouces
#include "..//Source/Resources/Resources.h"
#include "..//Source/Resources/ResourceManger.h"

//Components
#include "Components/TextureComponent.h"
#include "Components/TextComponents.h"
#include "Components/Component.h"
#include "Components/CollsionCompoents.h"
#include "Components/EnginePhysicsComponent.h"
#include "Components/PhyisicsComponent.h"
#include "Components/RenderComponent.h"
#include "Components/AudioComponent.h"
#include "Components/TextureAnimationComponent.h"

#include <cassert>
#include <Phyisics/Physics.h>
//#include <memory>

class Engine {

public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown() const;

	void Update();

	Renderer GetRenderer() const { return *renderer; }
	Input GetInput() const { return *input; }
	Audio GetAudio() const { return *audio; }
	Time GetTime() const { return *time; }
	ParticleSystem GetPS() const { return *particlesystem; }
	bool IsQuit() const { return quit; }
	Physics& GetPhysics() { return *physics; }

public:
	bool quit{ false };
	std::unique_ptr<Time> time;
	std::unique_ptr<Physics> physics;
	std::unique_ptr<Renderer> renderer;
	std::unique_ptr<Input> input;
	std::unique_ptr<Audio> audio;
	std::unique_ptr<ParticleSystem> particlesystem;
	std::unique_ptr<AudioSource> audioSource;
	std::unique_ptr<AudioClip> audioClip;
	std::unique_ptr<AudioComponent> audioComponent;
};

//Engine extern g_engine;
