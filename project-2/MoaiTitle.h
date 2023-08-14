#pragma once
#include "Scene.h"

namespace JSH
{
    class MoaiTitle : public Scene
    {
    public:
        MoaiTitle();
        virtual ~MoaiTitle();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void Enter();
        virtual void Exit();

    private:
        class BackGround* mBackGround;
    };
}