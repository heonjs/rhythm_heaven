#pragma once
#include "Scene.h"

namespace JSH
{
    class Cafe : public Scene
    {
    public:
        Cafe();
        virtual ~Cafe();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void Enter();
        virtual void Exit();

    private:

    };
}