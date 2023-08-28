#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiNPC : public GameObject
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

        MoaiNPC();
        virtual ~MoaiNPC();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void Idle();
        void Pressed();
        void KeyUp();
        void Touch();

        void Pattern();

    private:
        eState mState;
        static float mPlayTime;
        bool mFlag;

        static map<int, eState> mPattern;
    };
}