#pragma once
#include "Scene.h"

namespace JSH
{
    class TitleScene : public Scene
    {
    public:
        TitleScene();
        virtual ~TitleScene();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void Enter();
        virtual void Exit();

    private:

    };
}