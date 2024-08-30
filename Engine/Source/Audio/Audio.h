#pragma once
#include "Audio/AudioSource.h"
#include <fmod.hpp>
#include <map>
#include <string>

class AudioSource;
class AudioClip;

class Audio
{
public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool AddSound(const std::string& name);
	bool PlaySound(const std::string& name);

	FMOD::System* m_audio{ nullptr };
	std::map<std::string, FMOD::Sound*> sounds;

	friend AudioSource;
	friend AudioClip;
private:

};