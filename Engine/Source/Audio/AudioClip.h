#pragma once
#include "..//Resources/Resources.h"
#include "Audio/AudioSource.h"
#include <string>
#include "Audio.h"
#include <fmod.hpp>

class Audio;
class AudioSource;

class AudioClip : public Resource
{
public:
	AudioClip() = default;
	~AudioClip();
	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, class Audio& audio);
	//<allow the Audio and AudioSource class access to the m_sound data, remember friend ? >
	friend Audio;
	friend AudioSource;
private:
	FMOD::Sound* sounds{ nullptr };
};
