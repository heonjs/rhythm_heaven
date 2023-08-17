#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBCaptain : public GameObject
    {
    public:
        enum class eState
        {
            Idle,
            Talk,
            Fail,
            End
        };

        BBCaptain();
        virtual ~BBCaptain();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        void Idle();
        void Talk();
        void Fail();

        void CptPlay();

    private:
        eState mState;
    };
}