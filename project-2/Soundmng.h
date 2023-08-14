#pragma once
#include "Include.h"

namespace JSH
{
    class Soundmng
    {
    public:
        static bool Initialize();
        static LPDIRECTSOUND8 GetDevice()
        { 
            return mSoundDevice; 
        }

    private:
        static LPDIRECTSOUND8 mSoundDevice;
    };
}