#include "AudioSource.h"
#include <fmod_errors.h>
#include <iostream>

bool AudioSource::Play(Audio& audio, bool loop, float volume, float pitch)
{
    audioClip->sounds->setMode(loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF);

    FMOD_RESULT result = audio.m_audio->playSound(audioClip->sounds, 0, false, & channel);
    if (result != FMOD_OK)
    {
        std::cerr << "Error playing sound: " << FMOD_ErrorString(result); 
        return false;
    }
    SetVolume(volume);
    SetPitch(pitch);
    return true;
}

void AudioSource::Stop()
{
    if (IsPlaying())
    {
        channel->stop();
    };
}

void AudioSource::Pause(bool pause)
{
    FMOD_RESULT result = channel->setPaused(pause);
        if (result != FMOD_OK)
        {
            std::cerr << "Error pausing sound: " << FMOD_ErrorString(result);
        }
}

bool AudioSource::IsPlaying()
{
    bool isPlaying;
    FMOD_RESULT result = channel->isPlaying(&isPlaying);
        if (result != FMOD_OK)
        {
            std::cerr << "Error is playing sound: " << FMOD_ErrorString(result);
        }
    return isPlaying;
}

bool AudioSource::SetVolume(float volume)
{
    FMOD_RESULT result = channel->setVolume(volume);
        if (result != FMOD_OK)
        {
            std::cerr << "Error setting volume: " << FMOD_ErrorString(result);
            return false;
        }
    return true;
}

bool AudioSource::SetPitch(float pitch)
{
    FMOD_RESULT result = channel->setPitch(pitch);
        if (result != FMOD_OK)
        {
            std::cerr << "Error setting pitch: " << FMOD_ErrorString(result);
            return false;
        }
    return true;
}
