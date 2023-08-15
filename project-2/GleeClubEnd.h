#pragma once
#include "Scene.h"

namespace JSH
{
    class GleeClubEnd : public Scene
    {
    public:
        GleeClubEnd();
        virtual ~GleeClubEnd();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void Enter();
        virtual void Exit();

    private:
        class GleeEndImage* mGleeEnd;
    };
}