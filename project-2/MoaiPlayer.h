#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiPlayer : public GameObject
    {
    public:
        enum class eState
        {
            Idle,
            Pressed,
            KeyUp,
            Touch,
            End
        };

        MoaiPlayer();
        virtual ~MoaiPlayer();
        
        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void Idle();
        void Pressed();
        void KeyUp();
        void Touch();

    private:
        eState mState;
        static float mTime;
    };
}