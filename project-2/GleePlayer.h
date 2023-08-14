#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleePlayer : public GameObject
    {
    public:
        enum class eState
        {
            Idle,
            Closing,
            Opening,
            Touch,
            AH,
            End
        };

        GleePlayer();
        virtual ~GleePlayer();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void Idle();
        void Closing();
        void Opening();
        void Touch();
        void AH();

    private:
        eState mState;
    };
}