#pragma once
#include "AudioClip.h"
#include "Audio.h"

class Audio;
class AudioClip;

class AudioSource
{
public:
	AudioSource() = default;
	AudioSource(res_t<AudioClip> audioClip) : audioClip{ audioClip } { }
	~AudioSource() = default;
	bool Play(class Audio& audio, bool loop = false, float volume = 1, float pitch = 1);
	void Stop();
	void Pause(bool pause = true);
	void SetAudioClip(res_t<AudioClip> audioClip) { audioClip = audioClip; }
	bool IsPlaying();
	bool SetVolume(float volume);
	bool SetPitch(float pitch);

	friend Audio;
	friend AudioClip;
private:
	res_t<AudioClip> audioClip;
	FMOD::Channel* channel{ nullptr }; 
};