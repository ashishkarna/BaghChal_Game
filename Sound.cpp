#include "Sound.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool SoundClass::LoadSound()
{
    if (!Button.LoadFromFile("sounds/wood.wav"))
    {
        return false;
    }
    return true;
}

void SoundClass::PlaySound()
{
    sound.SetBuffer(Button);
    sound.Play();

    // Loop while the sound is playing
    while (sound.GetStatus() == Sound::Playing)
    {}
}
