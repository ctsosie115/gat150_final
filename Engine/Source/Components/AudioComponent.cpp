#include "AudioComponent.h"
#include "..//Resources/ResourceManger.h"
#include "..//Audio/AudioClip.h"
#include "..//Audio/Audio.h"
#include "..//Audio/AudioSource.h"
#include "..//FrameWork/Actor.h"
#include "..//FrameWork/Scene.h"

FACTORY_REGISTER(AudioComponent);


AudioComponent::AudioComponent(const AudioComponent& other)
{
	soundName = other.soundName;
	playOnStart = other.playOnStart;
	loop = other.loop;
	volume = other.volume;
	pitch = other.pitch;

	if (other.audioSource) {
		audioSource = std::make_unique<AudioSource>(*other.audioSource.get());
	}
}

void AudioComponent::Read(const json_t& value)
{
	AudioComponent::Initialize();
	
	Json::Read(value, "soundName", soundName);
	Json::Read(value, "playOnStart", playOnStart);
	Json::Read(value, "loop", loop);
	Json::Read(value, "volume", volume);
	Json::Read(value, "pitch", pitch);
}

void AudioComponent::Write(json_t& value)
{
}

void AudioComponent::Initialize()
{
	if (!audioSource && !soundName.empty())
	{
		//auto audioClip = ResourceManger::Instance().Get<AudioClip>(soundName, owner->m_scene->engine->GetAudio());
		auto audioClip = ResourceManger::Instance().Get<AudioClip>(soundName, owner->scene->engine->GetAudio());
		if (audioClip) {
			audioSource = std::make_unique<AudioSource>(audioClip);
		}
	}
}

void AudioComponent::Update(float dt)
{
	if (playOnStart) {
		playOnStart = false;
		Play();
	}
}

void AudioComponent::Play()
{
	//Unless Defalut
	if (audioSource) {
		Play(loop, volume, pitch);
	}
}

void AudioComponent::Play(bool loop, float volume, float pitch)
{
	audioSource->Play(*(owner->scene->engine->audio), loop, volume, pitch);
}

bool AudioComponent::IsPlaying()
{
	return audioSource->IsPlaying();
}

void AudioComponent::Stop()
{
	playOnStart = true;
	audioSource->Stop();
}

void AudioComponent::Pause(bool pause)
{
	audioSource->Pause(pause);
}

void AudioComponent::SetVolume(float volume)
{
	audioSource->SetVolume(volume);
}

void AudioComponent::SetPitch(float pitch)
{
	audioSource->SetPitch(pitch);
}
