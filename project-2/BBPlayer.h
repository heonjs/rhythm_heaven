#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBPlayer : public GameObject
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

        BBPlayer();
        virtual ~BBPlayer();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void Idle();
        void Hit();
        void Squat();
        void Stretch();

    private:
        eState mState;
    };
}