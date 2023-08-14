#pragma once
#include "Scene.h"

namespace JSH
{
    class MoaiEnd : public Scene
    {
    public:

        MoaiEnd();
        virtual ~MoaiEnd();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void Enter();
        virtual void Exit();

    private:

    };
}