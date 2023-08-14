#pragma once
#include "Scene.h"

namespace JSH
{
    class BlueBirdsTitle : public Scene
    {
    public:
        BlueBirdsTitle();
        virtual ~BlueBirdsTitle();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void Enter();
        virtual void Exit();

    private:
        class BackGround* mBackGround;
    };
}