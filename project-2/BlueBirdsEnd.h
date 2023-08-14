#pragma once
#include "Scene.h"

namespace JSH
{
    class BlueBirdsEnd : public Scene
    {
    public:
        BlueBirdsEnd();
        virtual ~BlueBirdsEnd();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void Enter();
        virtual void Exit();

    private:

    };
}