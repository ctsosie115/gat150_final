#pragma once
#include "Component.h"
class AudioComponent : public Component 
{
public:
	AudioComponent() = default;
	AudioComponent(const AudioComponent& other);

	static const char* GetTypeName() {
		return "AudioComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<AudioComponent>(*this);
	}

	void Initialize() override;
	void Update(float dt) override;
	void Play();
	void Play(bool loop, float volume, float pitch);
	bool IsPlaying();
	void Stop();
	void Pause(bool pause = true);
	void SetVolume(float volume);
	void SetPitch(float pitch);
public:
	bool playOnStart = false ;
	bool loop = false ;
	float volume = 1.0f;
	float pitch = 1.0f;
	std::string soundName;

private:
	std::unique_ptr<class AudioSource> audioSource;
};
