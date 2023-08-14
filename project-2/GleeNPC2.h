#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeNPC2 : public GameObject
    {
    public:
        enum class eState
        {
            Idle,
            Touch,
            Closing,
            Opening,
            AH,
            Success,
            Fail,
            End
        };

        GleeNPC2();
        virtual ~GleeNPC2();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void Idle();
        void Touch();
        void Closing();
        void Opening();
        void AH();
        void Success();
        void Fail();

    private:
        eState mState;
    };
}