#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBNPC : public GameObject
    {
    public:
        enum class eState
        {
            Idle,
            Hit,
            Squat,
            Stretch,
            End

        };
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
        eState mState;
    };
}