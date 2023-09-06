#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBNPC : public GameObject
    {
    public:
        BBNPC();
        virtual ~BBNPC();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        void Idle();
        void Hit();
        void Squat();
        void Stretch();

    private:
        static float mPlayTime;
        static float miTime;
    };
}