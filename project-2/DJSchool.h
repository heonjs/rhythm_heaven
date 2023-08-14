#pragma once
#include "Scene.h"

namespace JSH
{
    class DJSchool : public Scene
    {
    public:
        enum class eState
        {
            Idle,
            Touch,
            Slide,
            End
        };

        DJSchool();
        virtual ~DJSchool();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void Idle();
        void Touch();
        void Slide();

    private:
        eState mState;
    };
}