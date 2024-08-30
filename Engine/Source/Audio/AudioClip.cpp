#include "AudioClip.h"
#include "Audio.h"
#include <iostream>

AudioClip::~AudioClip()
{
    if (sounds = NULL)
    {
        sounds->release();
    }
}

bool AudioClip::Create(std::string name, ...)
{
    va_list args;
    va_start(args, name);
    Audio& audio = va_arg(args, Audio);
    va_end(args);
    return Load(name, audio);
    
}
bool AudioClip::Load(const std::string& filename, Audio& audio)
{
    audio.m_audio->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sounds);
    if (sounds == nullptr)
    {
        std::cerr << "Could not load sound: " << filename << std::endl;
        return false;
    }
    return true;
}
