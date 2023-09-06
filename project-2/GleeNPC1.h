#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeNPC1 : public GameObject
    {
    public:
        GleeNPC1();
        virtual ~GleeNPC1();

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