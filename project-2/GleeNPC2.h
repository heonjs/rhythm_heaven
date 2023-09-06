#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeNPC2 : public GameObject
    {
    public:
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
        void Fail();

    private:

    };
}